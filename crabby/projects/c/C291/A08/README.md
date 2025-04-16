+---------------------------------------------------------------------------------------------+
|                                                                                             |
|     A08: Mechanism to randomly generate a crew and allow the user to make changes to it     |
|                                                                                             |
+---------------------------------------------------------------------------------------------+

Program should randomly generate 10 crewmembers and display them to the user
The user shall also be presented with the following options:
    -D      Redisplay the table of crewmembers
    -N <#>  Provide a name for the specified crewmember
    -C <#>  Make specified crewmember the captain. (No other crewmember should have a higher rank than captain)
    -B <#>  Assign specified crewmember to bridge position, use single letter to indicate post
    -S      Save the crewmember list to a file "crewmember_list.txt"
    -R <#>  Regenerate the given crewmember
    -P      Allow user to play the game which will result in exiting the program
    NOTE: menu options requiring a crew number, use the assigned serial number
User may repeat the above menu options until P option is utilized.
Crew attributes:
    Name (limited by sys mem)
    Race
        Terran
        Martian
        Venusian
        Saturian
    Abilities
    Skills
    Captain (pointer to captain crewmember)
    Post (crewman by default unless assigned to bridge crew)
    Rank
    Service Number (6 digits)
    
