#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

const string Grean = "\033[32m"; // ANSI escape code for green text
const string reset = "\033[0m";  // ANSI escape code to reset text color

// Function to display the player's profile information in a formatted way
void details(string hello, string name, int point, int id, int lv)
{
    // Display player details in a structured format
    cout << "|================================|" << endl;
    cout << "|        Player Profile          |" << endl;
    cout << "|================================|" << endl;
    cout << "| Name: " << name << "                      |" << endl;
    cout << "| ID: # " << id << "                     |" << endl;
    cout << "| Points: " << point << "                      |" << endl;
    cout << "| Level: " << lv << "                       |" << endl;
    cout << "|--------------------------------|" << endl;
}

// Function to print a list of menu options or information
void list(vector<string> existing)
{
    // Iterate through the list and print each item
    for (string s : existing)
    {
        cout << s << endl;
    }
}

// Main game logic for a single stage
// Shows hints, gets guesses, updates points and level
void stages(vector<string>& words_level, vector<string>& hint, vector<string>& difficulty, int& level, int& points, int Attempts, int num_difficulty)
{
    int random_word = rand() % words_level.size(); // Select a random word for this stage
    string answer = "";
    bool gussed = false;

    for (int i = Attempts; i > 0; --i)
    {
        // Display current game state
        cout << "Point: " << points << endl;
        cout << "Level: " << level << endl;
        cout << "Difficulty: " << difficulty.at(num_difficulty) << endl;
        cout << "Number of attempts: " << i << endl;

        cout << "\nHints:-" << endl;
        cout << hint.at(random_word);
        cout << "\nGuess the word: ";
        cin >> answer;

        // Convert answer to lowercase for case-insensitive comparison
        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        if (answer == words_level.at(random_word))
        {
            // Award points based on word index
            if (random_word == 0) points += 100;
            else if (random_word == 1) points += 200;
            else if (random_word == 2) points += 300;
            else if (random_word == 3) points += 200;

            // Level up if enough points are earned
            if (points >= level * 200) level++;

            // Display success message
            cout << endl << "|-----------------------------------------------------|" << endl;
            cout << "| *************************************************** |" << endl;
            cout << "|* _________________________________________________* |" << endl;
            cout << "|* |                                               |* |" << endl;
            cout << "|* |" << Grean << "Congratulations, your guess is correct: " << words_level.at(random_word) << reset << "    |* |" << endl;
            cout << "|* |                                               |* |" << endl;
            cout << "|* |_______________________________________________|* |" << endl;
            cout << "|_____________________________________________________|" << endl;

            // Remove the guessed word and its hint from the lists
            words_level.erase(words_level.begin() + random_word);
            hint.erase(hint.begin() + random_word);
            gussed = true;

            system("pause");
            break;
        }
        else cout << "Wrong! Try again.\n";
        system("cls");
    }
    // Reveal the correct word if not guessed
    if (!gussed)
{
	cout << "I lost the word was: " << words_level.at(random_word) << endl;
	words_level.erase(words_level.begin() + random_word);
	hint.erase(hint.begin() + random_word);

}
    system("pause");
}

// Function to play through all words in a level
void play_level(vector<string>& words, vector<string>& hint, vector<string>& difficulty, int& level, int& points, int Attempts, int num_difficulty)
{
    while (!words.empty()) {
        stages(words, hint, difficulty, level, points, Attempts, num_difficulty);
        system("cls");
    }
}

// Function to open a promotional link in the default browser
void ads()
{
    system("start chrome https://linktr.ee/sa3dwy?utm_source=linktree_profile_share&ltsid=a1eacc81-c473-4b64-aca7-a14b408f7bc0");
}

// Main entry point of the program
int main()
{
    // Define word lists and hints for each level
    vector<string> level_one = { "water","sun","pen","house" };
    vector<string> hint_lv_one =
    {
        "Essential for life.",
        "Shines in the sky during the day.",
        "You write with it.",
        "A place where people live."
    };

    vector<string> level_two = { "computer","ocean","phone","key" };
    vector<string> hint_lv_two =
    {
        "Used for coding and gaming.",
        "Large body of salty water.",
        "Used to call someone.",
        "Opens a lock."
    };

    vector<string> level_three = { "galaxy","volcano","moon","airplane" };
    vector<string> hint_lv_three =
    {
        "Contains millions of stars.",
        "A mountain that erupts lava.",
        "Lights up the night without its own light",
        "Flies in the sky carrying people."
    };
    vector<string> level_foure = { "extinction","astronomy","alzheimer","metaverse" };
    vector<string> hint_lv_foure =
    {
        "Disappearance of a species.",
        "Science of stars and planets.",
        "A disease that weakens memory.",
        "A virtual world parallel to reality."
    };

    // Menu options for the main screen
    vector<string> existing =
    {
        "|------------------------------|",
        "|   ________________________   |",
        "| * |       The list       | * |",
        "| * |----------------------| * |",
        "| * |                      | * |",
        "| * |  #1 Profile          | * |",
        "| * |                      | * |",
        "| * |  #2 Started playing  | * |",
        "| * |                      | * |",
        "| * |  #0 Exit             | * |",
        "| * |______________________| * |",
        "|______________________________|"
    };

    vector<string> difficulty = { "Easy","Medium","Hard","Impossible" };

    srand(time(0)); // Seed random number generator
    int point = 0, id = rand(), lv = 1, pick;

    string name;
    cout << "Enter your name" << endl;
    cout << ": ";
    getline(cin, name);
    system("cls");

    // Main menu loop
    do
    {
        list(existing); // Show menu
        cout << "Invalid choice, please choose again." << endl;
        cout << ": ";
        cin >> pick;
        system("cls");
        while (pick < 0 || pick > 2)
        {
            list(existing);
            cout << "Invalid choice, please choose again." << endl;
            cout << ": ";
            cin >> pick;
            system("cls");
        }
        system("cls");
        if (pick == 1)
        {
            details("Welcome My Friend: ", name, point, id, lv); // Show profile
            system("pause");
        }
        else if (pick == 2)
        {
            char again;
            do
            {
                char show;

                // Play all levels sequentially
                play_level(level_one, hint_lv_one, difficulty, lv, point, 5, 0);
                play_level(level_two, hint_lv_two, difficulty, lv, point, 4, 1);
                play_level(level_three, hint_lv_three, difficulty, lv, point, 3, 2);
                play_level(level_foure, hint_lv_foure, difficulty, lv, point, 2, 3);

                cout << "do you need show details? (y/n)" << endl;
                cin >> show;
                system("cls");
                if (show == 'y' || show == 'Y')
                {
                    details("Details: ", name, point, id, lv); // Show profile after game
                }

                cout << "\n Do you want to try again? (y/n)" << endl;
                cout << ": ";
                cin >> again;

                system("cls");
            } while (again == 'y' || again == 'Y');

        }

        system("cls");
    } while (pick != 0);

    ads(); // Show promotional link before exit
    return 0;
}