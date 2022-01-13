#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int red = 0;
int yellow = 0;
int blue = 0;
int green = 0;

int add_a_marble() {
    int marble_color_add;

    cout << "Which color marble would you like to add: [1]:Red, [2]:Yellow, [3]:Blue, or [4]:Green" << endl;
    cin >> marble_color_add;

    switch (marble_color_add) {
        case 1: // Add a red marble.
            red++;
            cout << "One red marble has been added to the bag." << endl;
            cout << "There is now " << red << " red marble(s) in the bag." << endl;
            break;
        case 2: // Add a yellow marble.
            yellow++;
            cout << "One yellow marble has been added to the bag." << endl;
            cout << "There is now " << yellow << " yellow marble(s) in the bag." << endl;
            break;
        case 3: // Add a blue marble.
            blue++;
            cout << "One blue marble has been added to the bag." << endl;
            cout << "There is now " << blue << " blue marble(s) in the bag." << endl;
            break;
        case 4: // Add a green marble.
            green++;
            cout << "One green marble has been added to the bag." << endl;
            cout << "There is now " << green << " green marble(s) in the bag." << endl;
            break;
        default: // Default response if entry doesn't match case options.
            cout << "Sorry that entry wasn't recognized. Please try again." << endl;
    };
    return 0;
};

int remove_a_marble() {
    int marble_color_remove;

    cout << "Which color marble would you like to remove: [1]:Red, [2]:Yellow, [3]:Blue, or [4]:Green" << endl;
    cin >> marble_color_remove;

    switch (marble_color_remove) {
        case 1: // Remove a red marble.
            if (red != 0){
                red--;
                cout << "One red marble has been removed from the bag." << endl;
                cout << "There is now " << red << " red marble(s) in the bag." << endl;
            }
            else {
                cout << "There are no red marbles to remove." << endl;
            };
            break;
        case 2: // Remove a yellow marble.
            if (yellow != 0){
                yellow--;
                cout << "One yellow marble has been removed from the bag." << endl;
                cout << "There is now " << yellow << " yellow marble(s) in the bag." << endl;
            }
            else {
                cout << "There are no yellow marbles to remove." << endl;
            }
            break;
        case 3: // Remove a blue marble.
            if (blue != 0){
                blue--;
                cout << "One blue marble has been removed from the bag." << endl;
                cout << "There is now " << blue << " blue marble(s) in the bag." << endl;
            }
            else {
                cout << "There are no blue marbles to remove." << endl;
            }
            break;
        case 4: // Remove a green marble.
            if (green != 0){
                green--;
                cout << "One green marble has been removed from the bag." << endl;
                cout << "There is now " << green << " green marble(s) in the bag." << endl;
            }
            else {
                cout << "There are no green marbles to remove." << endl;
            }
            break;
        default: // Default response if entry doesn't match case options.
            cout << "Sorry that entry wasn't recognized. Please try again." << endl;
    };
    return 0;
};

int count_marbles() {
    int marble_count = red + yellow + blue + green;
    cout << "There are " << marble_count << " marbles in the bag.\n" << red << " red marbles\n" << yellow << " yellow marbles\n" << blue << " blue marbles\n" << green << " green marbles" << endl;
    return 0;
};

int count_marbles_quiet() { // count_marbles() but w/o cout blurb
    int marble_count = red + yellow + blue + green;
    return marble_count;
};

int menu_bag_empty(int menu_option, int escape_val) {
    cout << "The bag is empty! Would you like to [1]:Add a marble to the bag, [2]:Count the marbles in the bag, or [3]:Exit your digital marble bag." << endl;
    cin >> menu_option;

    switch (menu_option) {
        case 1: // Add a marble.
            add_a_marble();
            break;
        case 2: // Count marbles.
            count_marbles();
            break;
        default: // Exit.
            escape_val++;
            cout << "Thank you for visiting your digital marble bag. Goodbye." << endl;
    };
    return escape_val;
};

int menu_bag_full(int menu_option, int escape_val) {
    cout << "The bag is full! Would you like to [1]:Remove a marble from the bag, [2]:Count the marbles in the bag, or [3]:Exit your digital marble bag." << endl;
    cin >> menu_option;

    switch (menu_option) {
        case 1: // Remove a marble.
            remove_a_marble();
            break;
        case 2: // Count marbles.
            count_marbles();
            break;
        default: // Exit.
            escape_val++;
            cout << "Thank you for visiting your digital marble bag. Goodbye." << endl;
    };
    return escape_val;
};

int menu_bag_standard(int menu_option, int escape_val) {
    cout << "Would you like to [1]:Add a marble to the bag, [2]:Remove a marble from the bag, [3]:Count the marbles in the bag, or [4]:Exit your digital marble bag." << endl;
    cin >> menu_option;

    switch (menu_option) {
        case 1: // Add a marble.
            add_a_marble();
            break;
        case 2: // Remove a marble.
            remove_a_marble();
            break;
        case 3: // Count marbles.
            count_marbles();
            break;
        default: // Exit.
            escape_val++;
            cout << "Thank you for visiting your digital marble bag. Goodbye." << endl;
    };
    return escape_val;
};


int main() {
    // cout << "there are " << marble_bag_count() << " marbles in the bag." << endl;
    int menu_option;
    int escape_val = 0;

    cout << "Welcome to your digital marble bag." << endl;
    while(escape_val==0) {
        int fill_state = count_marbles_quiet();

        switch (fill_state) {
            case 0: // Bag is empty.
                escape_val = menu_bag_empty(menu_option, escape_val);
                break;
            case 100: // Bag is full.
                escape_val = menu_bag_full(menu_option, escape_val);
                break;
            default: // Bag is neither full nor empty.
                escape_val = menu_bag_standard(menu_option, escape_val);
        };
    };
    return 0;
}
