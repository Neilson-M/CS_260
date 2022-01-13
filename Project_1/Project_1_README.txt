look into array + stack for marble bag
LIFO (last in, first out)
is top = NULL, = is empty

pre-conditions: anything we can prove to be true before a certain operation
post-conditions: something we know to be true after a certain operation

-----------------
// Worth noting that while I have used the basic counter system you showed me after class as inspiration,
// I have done my best to expand and improve on it (without getting too complicated).
How to model a bag of marbles:
    Properties/Variables:
        Capacity of the marble bag
        Count of marbles in the marble bag
        Count of marbles of a specific color

    Behaviors/Methods:
        Add a marble to the bag
        Remove a marble from the bag
        Count the marbles in the bag
        General menu navigation
    
    A marble is represented as a running tally of each color of marble present in the bag.

    A marble's properties (color) are gathered and added to the bag through user input.

    A marble is removed from the bag by selecting color through user input and subtracting one from
    the indicated color tally. If there are none left, cout a line stating that there are none left.


    A note on the main menu: The menu will be "smart" in that it is intended to detect the fill state
    of the bag. If the bag is empty, the option to remove a marble will not be shown. Conversely, if
    the bag is full, the option to add a marble will not be shown.


    Some tests would be:
        Test if the bag is empty -  This is handled through the main menu. If the bag is empty, the
        option to remove a marble will not be visible.
        Test if the bag is full -  This is handled through the main menu. If the bag is full, the
        option to add a marble will not be visible.
        Make sure marbles are getting added/removed correctly - Run 'add a marble'/'remove a marble'
        and then run 'list marbles' to ensure the right marble(s) were added/removed.


-----------------
// Unfortunately, this is too complex. Leaving this here for record purposes as to what I had originally
// wanted to do. Most of the concepts have been copied as close as possible but it has been slimmed
// down considerably.
How to model a bag of marbles:
    Properties/Variables:
        Capacity of the marble bag
        Count of marbles in the marble bag
        Identity of currently selected marble

    Behaviors/Methods:
        Add a marble to the bag
        Remove a marble from the bag
        Count the marbles in the bag
        Look at the last marble put in the bag

    A marble is a list object that contains 2 descriptors: Color and Size.
        Color and Size will be randomly selected (using random integer generation) from a short list.
    
    The marble bag is a stack. Marbles will be added and taken out via LIFO.
    They will be added and removed via .push() and .pop()

    Some tests would be:
        Test if the bag is empty - This is done within the Remove a marble method.
            if not stack.empty() then .pop()
            else cout << "The bag is empty!"
        Test if the bag is full/Try to overfill the bag.
            When adding marbles to the bag, if the last marble added would cause the bag to reach
            full capacity, the method is ended early and cout "The bag is now full."
        Test that the bag is storing marbles accurately.
            Use .top() to save to a variable and cout the properties of the top marble.
            Then compare with the properties when extracted with .pop()
                (This method is guaranteed to succeed since there's no change done to the marble
                but I can't really think of a different way to test accuracy for this.)
        
