#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#define SONG 1
#define VID 2
#define IMG 3
#define OTH 4

using std ::cin;
using std ::cout;
using std ::endl;
using std ::istringstream;
using std ::remove;
using std ::replace;
using std ::string;
using std ::stringstream;
using std ::vector;

void findingType(int &songSize, int &vidSize, int &imgSize, int &oSize,int StringNumber);

int main(void)
{
    int songSize = 0;
    int vidSize = 0;
    int imgSize = 0;
    int oSize = 0;
    int num;
    string str;

    vector<int> vect;

    getline(cin, str);

    istringstream in(str);

    /*Storing Test Cases and Each Test number of String in a Vector*/
    while (in >> num)
    {
        vect.push_back(num);
    }
    // printf("%d %d %d ", vect[0],vect[1],vect[2]);
    for (int i = 0; i < vect[0]; i++)
    {
        findingType(songSize, vidSize, imgSize, oSize,vect[i+1]);
        cout << "Song: " << songSize << "B"
             << " Movies: " << vidSize << " Images: " << imgSize << " Others: " << oSize << endl;
        songSize = 0;
        vidSize = 0;
        imgSize = 0;
        oSize = 0;
    }

    return 0;
}

void findingType(int &songSize, int &vidSize, int &imgSize, int &oSize,int StringNumber)
{
    string s{};
    string Str{};
    stringstream ss{};
    string temp{};
    int num;
    int size;
    char cond;
    fflush(stdin);
    // flushall(stdin);
    while (StringNumber >= 1 && getline(cin,s))
    {
        cond = OTH;
        num = 0;
        /*Used for Removing all Dots from the String*/
        // s.erase(remove(s.begin(), s.end(),'.'), s.end());

        /*Used for Replacing all Dots with white spaces in given String*/
        replace(s.begin(), s.end(), '.', ' ');

        /*inserting String in stringstream Variable*/
        ss << s;
        while (ss.eof() != true)
        {
            // Storing each word in the temp string..
            ss >> temp;
            // Checking if the string temp is an int or not..
            if (temp == "mp3" || temp == "flac" || temp == "aac")
            {
                cond = SONG;
            }
            else if (temp == "jpg" || temp == "bmp" || temp == "gif")
            {
                cond = IMG;
            }
            else if (temp == "mp4" || temp == "avi" || temp == "mkv")
            {
                cond = VID;
            }
            if ((stringstream)temp >> num)
            {
                size = num;
                cout << num << endl;
            }
            temp = "";
        }
        if (cond == SONG)
        {
            songSize += size;
        }
        else if (cond == VID)
        {
            vidSize += size;
        }
        else if (cond == IMG)
        {
            imgSize += size;
        }
        else
        {
            oSize += size;
        }
        ss.str("");
        ss.clear();
        StringNumber--;
    }
}
