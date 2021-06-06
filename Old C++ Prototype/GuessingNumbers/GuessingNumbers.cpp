// There is the potential that the user will automatically win. The variable used to determine the win condition is intitalised with the number 1, which, if it achieves a 1/100 chance, the player will win if they
//fall into the error trapping
//not entirely certain why the number has to be intialised, but it's neccesary

#include <iostream>
#include <string>

int main()
{
    //setup namespace for lazy. Fuck writing std:: in front of everything
    using namespace std;
    //make the random actualy random
    srand(time(0));

    //setup variables
    bool exit = false;
    int number, guess, length, count;
    string input;
    count = 0;

    //setup array with responses
    string responses[101] = { "Wait, what did you do? You're not supposed to see this message! Yeet a screenshot of this to MrFalcon#8899 on Discord", "\nWow you suck at this.\n",
"\nHave you tried guessing the right number?\n",
"\nThat guess was waaaaaay off\n",
"\nHahahahaha!\n",
"\nIf you keep it up like this I think you will never get the right number.\n",
"\nMaybe you should ask for some help\n",
"\nHey, here's a hint: The number you guessed wrong was 7!\n",
"\nIf you win I will give you 20 bucks.\n",
"\nWith every guess you get wrong, I grow in power.\n",
"\nDid you know the original DOOM was coded in C?\n",
"\nOther people have guessed the right number faster than you.\n",
"\nHave you tried cheating? I hear it's pretty effective.\n",
"\nMaybe this is a bit too hard? Naaaaah fuck you!\n",
"\nHey, here's a hitn: The number you guessed wrong was 14!\n",
"\nI have a feeling your IQ is a little too low for this.\n",
"\nTry guessing harder.\n",
"\nSo close!\n",
"\nSo very very close!\n",
"\nDo you know hard hard it is to watch this?\n",
"\nI think I know what you're going to guess next.\n",
"\nThat was a terrible guess!\n",
"\nHave you tried 69? :D\n",
"\nIt's just a 1% chance to get it right. It's not that hard!\n",
"\nYou can do it, I believe it you! That's what I would have said if you didn't suck so badly at this.\n",
"\nHey, can I take a nap?\n",
"\nThere are so many better games that you could be playing than this.\n",
"\nNot long until you guess the wrong number again.\n",
"\nHey, here's a hint: The number that you guessed wrong was 28!\n",
"\nWhile you're doing that I'm gonna read a book.\n",
"\nI've been looking up what your friends think about you and the concensus is that you suck.\n",
"\nI don't like you.\n",
"\nThere are a lot of things wrong with that guess.\n",
"\nThat number must be the amount of times you got rejected!\n",
"\nI've been waiting for someone who can guess the right answer, and looking at you I'm gonna be dissapointed.\n",
"\nNever gonna give you up, never gonna let you down. Never gonna turn around and desert you.\n",
"\nNever gonna make you cry, never gonna say goodbye. Never gonna tell a lie and hurt you.\n",
"\n*Groan*\n",
"\nHow long have you been at this?\n",
"\nAnd you call yourself a gamer?\n",
"\nCome on, all you have to do is guess the right number!\n",
"\nGet someone else to guess, you suck at this.\n",
"\nYour mom would give me better guesses than this.\n",
"\nhttps://cheatengine.org/\n",
"\nNext you should guess how many of your friends are really your friends.\n",
"\nI'm going to kill you if you get it wrong again!\n",
"\nThat was... You know what? I'm not going to say anything.\n",
"\nAre you even trying?\n",
"\nYour luck has run out it seems.\n",
"\nI'm going to get a snack.\n",
"\nUwU\n",
"\nI've been looking up what kind of people can't guess the right number, and all research says that those people look really ugly.\n",
"\nAre you done?\n",
"\nIf you get the right number I'll hang out with you.\n",
"\nSome people shouldn't be guessing numbers.\n",
"\nDo you have Corona? I think you have Corona.\n",
"\nHey, here's a hint: The number that you guessed wrong was 56!\n",
"\nAll these number's I'm thinking of aren't really random, but you wouldn't know that.\n",
"\nOne day you'll probably get it right.\n",
"\nWhat if I told you all the winners of this game get to go to a super secret discord where they discuss how to win this game?\n",
"\n60? Have you tried that one yet?\n",
"\nI find guessing my birthday of the month gets me to win this game.\n",
"\nSend this game to a friend, they'll just love this game :)\n",
"\n:(\n",
"\n:)\n",
"\n:D\n",
"\nD:\n",
"\nAre you satisfied yet?\n",
"\nTry taking a shot every time you guess wrong.\n",
"\nI'm gonna take a shower. I have to clean off your disgusting guess.\n",
"\nMaybe I should make this more difficult for you. I can see you're struggling.\n",
"\n*Yawn*\n",
"\nI'm dissapointed.\n",
"\nWanna hear a funny joke? No wait, you're here to guess numbers\n",
"\nHave you tried giving up?\n",
"\nWow. Just wow.\n",
"\nCould you really have guessed a more boring number?\n",
"\nOne day.\n",
"\nI've been waiting for you to guess that number. Wait did you think it was right?\n",
"\nI wonder how many more you will guess?\n",
"\nBooooooooo.\n",
"\nHave you tried not sucking?\n",
"\nAbsolutely outstanding.\n",
"\nTotally haven't seen that one before.\n",
"\nI knew you would guess that one, so I thought of a different number.\n",
"\nMaybe you should have guessed that one before. I used to think about that number a lot.\n",
"\nHey, that reminds me of something. No, wait. It's gone.\n",
"\nAre you having fun?\n",
"\nTry again.\n",
"\nI've seen better guesses.\n",
"\nBit of a stretch that one, don't you think?\n",
"\nI like your moxie, but not enough to give you a win.\n",
"\nEver seen Bruce Almighty? Yea this is sort of like that but worse.\n",
"\nTry harder.\n",
"\nOh? You guessed that one? Bit of a shame you did.\n",
"\nIt was 95! How could you not know that!?\n",
"\nGive me a break!\n",
"\nYou didn't really try, now did you?\n",
"\nTry bigger numbers.\n",
"\nTry smaller numbers.\n",
"\nNope.\n" };

    //introduction
    cout << "In this program, you have to guess what number I'm thinking of between 1 and 100.\n";
    cout << "Every time that you guess wrong I will think of a new number.\n";
    cout << "If you give up, simply state 'I suck' and I shall stop pestering you. Good Luck!\n";

    //begin loop
    do
    {
        //generate number and clear guess to avoid 69 glitch
        number = rand() % 100 + 1;
        guess = 1;
        cout << "\nWhat number am I thinking of?\n";        

        //get input and length for joke check and add answer count
        getline(cin, input);
        length = input.length();
        count++;

        //error catching to prevent string breaking program
        try
        {
            //convert input to number (for some reason you can grab the input here, you have to convert it for error catching to work)
            guess = stoi(input);

            //check if input was correct and assign end loop
            if (guess == number)
            {
                cout << "You're correct! Wow!\n";
                exit = true;
            }
        }

        //report error
        catch (invalid_argument const& e)
        {
            cout << input << "? Give me a number!\n";
        }

        //check if answer was not correct. Placed here to allow error to make sense. Special conditions also here to catch edge cases for funny response
        if (exit != true)
        {
            if (guess == 69)
            {
                cout << "\nNice. How bout we ditch this game and get guessing more than numbers?\n";
            }
            else if ((guess < 1) or (guess > 100))
            {
                cout << "\nI see you're guessing " << guess << "? Weren't you listening when I explained the game?!\n";
            }
            else if (length > 3)
            {
                cout << "\nReally? Two numbers? Are you that desperate?\n";
            }
            else
            {
                cout << responses[number];
            }
            cout << "Do you give up?\n";
            //cin.ignore();
            getline(cin, input);
        }

        //check if user wants to exit the program
        if (input == "I suck")
        {
            cout << "\nHahaha\n";
            exit = true;
        }
        
    }     
    //end loop condition
    while(exit == false);

    //goodbye user. getline() is used to pause output and allow user to see end text
    cout << "You made " << count << " guesses, what a waste of time! \nSee you next time, sucker!\n";
    getline(cin, input);
}
