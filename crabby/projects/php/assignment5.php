<?php
                        // +----------------+
                        // |                |
                        // |     PART B     |
                        // |                |
                        // +----------------+
// Function to sanitize any data that the user may input
function sanitizer($data) {
    return htmlspecialchars(stripslashes(trim($data)));
}

$errors = [];       // Variable storing all errors that are thrown during form handling
$success = "";      // Variable storing empty string to manipulate on success
// $uploadsDir = "~/crabby/projects/php/";
$uploadsDir = __DIR__;                      // Main directory to utilize
$csvFile = "$uploadsDir/applicants.csv";    // location of csv file inside main directory

// VALIDATION -- BEGIN UPON POST
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = sanitizer($_POST['full-name'] ?? '');   // Store user name and sanitize their input
    $gender = intval($_POST['gender'] ?? 0);        // Store gender as an integer value
    $languages = $_POST['languages'] ?? [];         // Store languages 
    $agreed = isset($_POST['agree']);               // Store boolean representing whether or not terms have been agreed to
    $filename = '';                                 // Store name of uploaded file

    // name validation -- get length of supplied name, and verify it contains a space and is between 5-25 chars
    $charCount = strlen($name);
    if ($charCount < 5 || $charCount > 25 || strpos($name, ' ') === false) {
        $errors[] = "Full Name must include 5-25 characters and at least one space."; // Throw if name is invalid
    }
    // terms agreement validation, if user has not agreed, throw following error
    if (!$agreed) {
        $errors[] = "You must agree to the terms and conditions.";
    }

    // file validation -- ensure file has been uploaded and doesn't hold errors
    if (isset($_FILES['resume']) && $_FILES['resume']['error'] == 0) {
        $fileType = mime_content_type($_FILES['resume']['tmp_name']);   // Store filetype
        $fileSize = $_FILES['resume']['size'];                          // Store file size
        if ($fileType !== 'application/pdf') {                          // If filetype is not pdf,
            $errors[] = "Only pdf files are accepted.";                 // <- throw this error
        }
        if ($fileSize > 2 * 1024 * 1024) {                              // If file size is greater than 2MB,
            $errors[] = "File must be less than 2MB.";                  // <- throw this error
        }
        if (empty($errors)) {                                           // If there are no errors,
            $timestamp = time();                                        // get timestamp,
            $filename = $timestamp . ".pdf";                            // save filename as $timestamp.pdf
            move_uploaded_file($_FILES['resume']['tmp_name'], "$uploadsDir/$filename"); // move the file to $uploadsDir for viewing
        }
    } else {                                // If not all conditions are met, do not upload the file and,
        $errors[] = "File upload failed.";  // <- throw this as error
    }

                        // +----------------+
                        // |                |
                        // |     PART C     |
                        // |                |
                        // +----------------+
    
    if (empty($errors)) {                   // furthermore if there are still no errors, parse selected languages,
        $langString = implode("|", array_map('sanitizer', $languages)); // save them as a string,
        $line = "$name,$gender,$langString,$filename\n";                // put that string in a variable following name and gender, and followed by filename
        file_put_contents($csvFile, $line, FILE_APPEND);    // write $line to applicants.csv
        $success = "Form submission successful.";           // display success message
    }
}

$submissions = [];              // submissions array
if (file_exists($csvFile)) {
    $submissions = file($csvFile, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES); // store file contents in $submissions
}
?>



<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Resume Submission</title>
    <style>         <!-- Styling for form and submission table --->
        body { font-family: Iosevka Nerd Font Mono; margin: 40px; }
        table.form-table { border-collapse: collapse; }
        table.form-table td { padding: 8px; }
        table.submissions-table { width: 100%; border-collapse; collapse; margin-top: 30px; }
        table.submissions-table th, table.submissions-table td {
            border: 1px solid #ddd; padding: 10px;
        }
        table.submissions-table th { background-color: #f2f2f2; }
        .error { color: red; }
        .success { color: green; }
    </style>
</head>
<body>



<!--
                        // +----------------+
                        // |                |
                        // |     PART A     |
                        // |                |
                        // +----------------+
--->
<h2>Resume Submission Form</h2>
<?php
if (!empty($errors)) {                                  // snippet to display any errors
    echo '<div class="error"><ul>';
    foreach ($errors as $error) echo "<li>$error</li>";
    echo '</ul></div>';
}
if ($success) echo "<div class='success'>$success</div>"; // snippet to display success message
?>
<!-- RESUME SUBMISSION FORM -->
<form action="assignment5.php" method="post" enctype="multipart/form-data">
    <table class="form-table">
        <tr>
            <td><label for="full-name">Full Name:</label></td>
            <td><input type="text" id="full-name" name="full-name" required></td>
        </tr>
        <tr>
            <td>Gender:</td>
            <td>
                <input type="radio" name="gender" value="1" required> Male
                <input type="radio" name="gender" value="2"> Female
                <input type="radio" name="gender" value="3"> Other
            </td>
        </tr>
        <tr>
            <td><label for="languages">Preferred Languages:</label></td>
            <td>
                <select name="languages[]" multiple size="4" id="languages">
                    <option value="English" selected>English</option>
                    <option value="Spanish">Spanish</option>
                    <option value="French">French</option>
                    <option value="German">German</option>
                </select>
            </td>
        </tr>
        <tr>
            <td><label for="resume">Resume Upload:</label></td>
            <td><input type="file" name="resume" id="resume" accept="application/pdf" required></td>
        </tr>
        <tr>
            <td><label for="agree">I agree to the terms and conditions</label></td>
            <td><input type="checkbox" id="agree" name="agree" required></td>
        </tr>
        <tr>
            <td><button type="submit">Submit Resume</button></td>
        </tr>
    </table>
</form>



<!--
                        +----------------+
                        |                |
                        |     PART D     |
                        |                |
                        +----------------+
--->
<h3>Submitted Applications</h3>
<?php if (count($submissions) > 0): ?> <!-- If entries exist in applicants.csv, display them as follows -->
    <table class="submissions-table">
        <tr>
            <th>Full Name</th>
            <th>Gender</th>
            <th>Languages</th>
            <th>Resume</th>
        </tr>
        <?php foreach ($submissions as $line):
            list($name, $gender, $lang, $file) = explode(",", $line);
            $genderText = ["1" => "Male", "2" => "Female", "3" => "Other"][$gender] ?? "Unknown";
            ?> <!-- snippet to convert gender radio values from integer to string -->
            <tr>
                <td><?= htmlspecialchars($name) ?></td> <!-- Sanitize Name before displaying --->
                <td><?= $genderText ?></td>
                <td><?= htmlspecialchars(str_replace('|', ', ', $lang)) ?></td> <!-- Sanitize Name before displaying --->
                <td><a href="<?= htmlspecialchars($file) ?>" target="_blank">View Resume</a></td>
            </tr>
        <?php endforeach; ?>
    </table>
<?php else: ?>
    <p>No submissions</p>
<?php endif; ?>

</body>
</html>
