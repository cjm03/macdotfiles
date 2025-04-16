from PIL import Image, ImageDraw

# Image size
width, height = 2560, 1440

# Colors
bg_color = (8, 12, 16)  # Hex #080c10
dot_color = (8, 12, 16)  # Hex #292929 prev: #191919

# Dot properties
dot_size = 2  # Small dot size
spacing = 20  # Space between dots

# Create image with background color
image = Image.new("RGB", (width, height), bg_color)
draw = ImageDraw.Draw(image)

# Draw dots in a grid pattern
for x in range(0, width, spacing):
    for y in range(0, height, spacing):
        draw.ellipse((x - dot_size // 2, y - dot_size // 2, x + dot_size // 2, y + dot_size // 2), fill=dot_color)

# Save the image
image.save("grid_pattern.png")
print("Image saved as grid_pattern.png")

