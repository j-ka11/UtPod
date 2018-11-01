<<<<<<< HEAD
//
// Created by Josh Kall Chris Erattuparambil on 10/24/2018.
//
/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "UtPod.h"
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    int result;
    unsigned int timeSeed = ((unsigned) time(0));
    srand(timeSeed);
    //0 Songs in UtPod
    t.showSongList();
    cout << "called showSongList" << endl;
    Song testingZero("Beatles", "Hey Jude1", 4);
    cout << "created a test song" << endl;
    result = t.removeSong(testingZero);
    cout << "result of removing a song with 0 songs is " << result << endl;
    t.shuffle();
    cout << "finished shuffle" << endl;
    t.sortSongList();
    cout << "finished sorting" << endl;
    t.showSongList();
    cout << "finished the last showSongList" << endl;
    int totalMemory = t.getTotalMemory();
    cout << "total memory in UtPod is " << totalMemory << endl;
    int remainingMemory = t.getRemainingMemory();
    cout << "remaining memory for songs is " << remainingMemory << endl;
    cout << "\n\n\n";

    //1 Song in UtPod
    cout << "testing for 1 song in UtPod" << endl;
    Song testingOne("Travis Scott", "5% Tint", 3);
    result = t.addSong(testingOne);
    cout << "result of adding a song is " << result << endl;
    t.showSongList();
    t.shuffle();
    cout << "finished shuffle" << endl;
    t.sortSongList();
    cout << "finished sorting" << endl;
    t.showSongList();
    cout << "finished the last showSongList" << endl;
    totalMemory = t.getTotalMemory();
    cout << "total memory in UtPod is " << totalMemory << endl;
    remainingMemory = t.getRemainingMemory();
    cout << "remaining memory for songs is " << remainingMemory << endl;
    result = t.removeSong(testingOne);
    cout << "result of removing a song with 1 song is " << result << endl;
    t.showSongList();
    cout << "printed song list" << endl;
    t.clearMemory();
    cout<<"cleared mem"<<endl;
    cout << "\n\n\n";

    //testing 2 songs
    cout << "testing for 2 song in UtPod" << endl;
    Song testingTwo("Drake", "Nonstop", 5);
    result = t.addSong(testingTwo);
    cout << "result of adding a song is " << result << endl;
    Song testingThree("Travis Scott ft. Weeknd", "Wake Up", 4);
    result = t.addSong(testingThree);
    cout << "result of adding a song is " << result << endl;
    t.showSongList();
    t.shuffle();
    cout << "finished shuffle" << endl;
    t.showSongList();
    cout << "printed song list" << endl;
    t.sortSongList();
    cout << "finished sorting" << endl;
    t.showSongList();
    cout << "finished the last showSongList" << endl;
    totalMemory = t.getTotalMemory();
    cout << "total memory in UtPod is " << totalMemory << endl;
    remainingMemory = t.getRemainingMemory();
    cout << "remaining memory for songs is " << remainingMemory << endl;
    int resultremoveTwo = t.removeSong(testingThree);
    cout << "result of removing a song with 2 song is " << resultremoveTwo << endl;
    t.showSongList();
    cout << "printed song list" << endl;
    t.clearMemory();
    cout << "\n\n\n";

    //testing 10 songs
    cout << "testing 10 songs in the UtPod" << endl;
    result = 0;
    Song s1("Drake", "Nonstop", 10);
    result = t.addSong(s1);
    Song s2("Travis Scott", "5% Tint", 11);
    result = result + t.addSong(s2);
    Song s3("Travis Scott ft. The Weeknd", "Wake up", 15);
    result = result + t.addSong(s3);
    Song s4("A$AP Rocky", "Praise the Lord", 12);
    result = result + t.addSong(s4);
    Song s5("Beatles", "Hey Jude", 4);
    result = result + t.addSong(s5);
    Song s6("Nicki Minaj", "Good Form", 20);
    result = result + t.addSong(s6);
    Song s7("Kendrick Lamar", "Alright", 8);
    result = result + t.addSong(s7);
    Song s8("Dua Lipa", "Hey Jude", 23);
    result = result + t.addSong(s8);
    Song s9("Drake", "Nonstop", 11);
    result = result + t.addSong(s9);
    Song s10("Logic", "Alright", 8);
    result = result + t.addSong(s10);
    cout << "total result of adding 10 songs is " << result << endl;
    t.showSongList();
    t.sortSongList();
    cout << "sorted songs\n" << endl;
    t.showSongList();
    t.shuffle();
    cout << "\n" << "finished shuffling" << endl;
    t.showSongList();
    t.sortSongList();
    cout << "\nsorted song list again" << endl;
    t.showSongList();
    t.shuffle();
    cout << "\nshuffling song list again" << endl;
    t.showSongList();

    Song song1("Christina Aguilera", "Genie in a Bottle", 3);                       //testing of operation overloads from here
    Song song2("Lil Wayne", "Dedicate", 4);                                         //
    Song song3("Lil Wayne", "Uproar", 4);                                           //
    /*bool song1First, song2First;                                                    //
    bool dedicateIsFirst, uproarIsFirst;                                            //
    if(song1 < song2){                                                              //
        song1First = true;                                                          //
        song2First = false;                                                         //
    }else {                                                                         //
        song1First = false;                                                         //
        song2First = true;                                                          //
    }                                                                               //
    if(song3 > song2){                                                              //
        dedicateIsFirst = true;                                                     //
        uproarIsFirst = false;                                                      //
    }else{                                                                          //
        dedicateIsFirst = false;                                                    //
        uproarIsFirst = true;                                                       //
    }                                                                               //
    cout << "\n\n\nsong1 is " << song1.getTitle() << " by " << song1.getArtist() << endl; //
    cout << "song2 is " << song2.getTitle() << " by " << song2.getArtist() << endl; //
    cout << "song3 is " << song3.getTitle() << " by " << song3.getArtist() << endl; //
    cout << "song1First is " << song1First << endl;                                 //
    cout << "song2First is " << song2First << endl;                                 //
    cout << "dedicateIsFirst is " << dedicateIsFirst << endl;                       //
    cout << "uproarIsFirst is " << uproarIsFirst << endl;                           //to here
*/
}
=======
//
// Created by Josh Kall Chris Erattuparambil on 10/24/2018.
//
/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    int result;

    //0 Songs in UtPod
    t.showSongList();
    cout << "called showSongList" << endl;
    Song testingZero("Beatles", "Hey Jude1", 4);
    cout << "created a test song" << endl;
    result = t.removeSong(testingZero);
    cout << "result of removing a song with 0 songs is " << result << endl;
    t.shuffle();
    cout << "finished shuffle" << endl;
    t.sortSongList();
    cout << "finished sorting" << endl;
    t.showSongList();
    cout << "finished the last showSongList" << endl;
    int totalMemory = t.getTotalMemory();
    cout << "total memory in UtPod is " << totalMemory << endl;
    int remainingMemory = t.getRemainingMemory();
    cout << "remaining memory for songs is " << remainingMemory << endl;
    cout << "\n\n\n";

    //1 Song in UtPod
    cout << "testing for 1 song in UtPod" << endl;
    Song testingOne("Travis Scott", "5% Tint", 3);
    result = t.addSong(testingOne);
    cout << "result of adding a song is " << result << endl;
    t.showSongList();
    t.shuffle();
    cout << "finished shuffle" << endl;
    t.sortSongList();
    cout << "finished sorting" << endl;
    t.showSongList();
    cout << "finished the last showSongList" << endl;
    totalMemory = t.getTotalMemory();
    cout << "total memory in UtPod is " << totalMemory << endl;
    remainingMemory = t.getRemainingMemory();
    cout << "remaining memory for songs is " << remainingMemory << endl;
    result = t.removeSong(testingOne);
    cout << "result of removing a song with 1 song is " << result << endl;
    t.showSongList();
    cout << "printed song list" << endl;
    t.clearMemory();
    cout<<"cleared mem"<<endl;
    cout << "\n\n\n";

    //testing 2 songs
    cout << "testing for 2 song in UtPod" << endl;
    Song testingTwo("Drake", "Nonstop", 5);
    result = t.addSong(testingTwo);
    cout << "result of adding a song is " << result << endl;
    Song testingThree("Travis Scott ft. Weeknd", "Wake Up", 4);
    result = t.addSong(testingThree);
    cout << "result of adding a song is " << result << endl;
    t.showSongList();
    t.shuffle();
    cout << "finished shuffle" << endl;
    t.showSongList();
    cout << "printed song list" << endl;
    t.sortSongList();
    cout << "finished sorting" << endl;
    t.showSongList();
    cout << "finished the last showSongList" << endl;
    totalMemory = t.getTotalMemory();
    cout << "total memory in UtPod is " << totalMemory << endl;
    remainingMemory = t.getRemainingMemory();
    cout << "remaining memory for songs is " << remainingMemory << endl;
    int resultremoveTwo = t.removeSong(testingThree);
    cout << "result of removing a song with 2 song is " << resultremoveTwo << endl;
    t.showSongList();
    cout << "printed song list" << endl;
    t.clearMemory();
    cout << "\n\n\n";

    //testing 10 songs
    cout << "testing 10 songs in the UtPod" << endl;
    result = 0;
    Song s1("Drake", "Nonstop", 10);
    result = t.addSong(s1);
    Song s2("Travis Scott", "5% Tint", 11);
    result = result + t.addSong(s2);
    Song s3("Travis Scott ft. The Weeknd", "Wake up", 15);
    result = result + t.addSong(s3);
    Song s4("A$AP Rocky", "Praise the Lord", 12);
    result = result + t.addSong(s4);
    Song s5("Beatles", "Hey Jude", 4);
    result = result + t.addSong(s5);
    Song s6("Nicki Minaj", "Good Form", 20);
    result = result + t.addSong(s6);
    Song s7("Kendrick Lamar", "Alright", 8);
    result = result + t.addSong(s7);
    Song s8("Dua Lipa", "Hey Jude", 23);
    result = result + t.addSong(s8);
    Song s9("Drake", "Nonstop", 11);
    result = result + t.addSong(s9);
    Song s10("Logic", "Alright", 8);
    result = result + t.addSong(s10);
    cout << "total result of adding 10 songs is " << result << endl;
    t.showSongList();
    t.sortSongList();
    cout << "sorted songs\n" << endl;
    t.showSongList();
    t.shuffle();
    cout << "\n" << "finished shuffling" << endl;
    t.showSongList();
    t.sortSongList();
    cout << "\nsorted song list again" << endl;
    t.showSongList();
    t.shuffle();
    cout << "\nshuffling song list again" << endl;
    t.showSongList();

    Song song1("Christina Aguilera", "Genie in a Bottle", 3);                       //testing of operation overloads from here
    Song song2("Lil Wayne", "Dedicate", 4);                                         //
    Song song3("Lil Wayne", "Uproar", 4);                                           //
    bool song1First, song2First;                                                    //
    bool dedicateIsFirst, uproarIsFirst;                                            //
    if(song1 < song2){                                                              //
        song1First = true;                                                          //
        song2First = false;                                                         //
    }else {                                                                         //
        song1First = false;                                                         //
        song2First = true;                                                          //
    }                                                                               //
    if(song3 > song2){                                                              //
        dedicateIsFirst = true;                                                     //
        uproarIsFirst = false;                                                      //
    }else{                                                                          //
        dedicateIsFirst = false;                                                    //
        uproarIsFirst = true;                                                       //
    }                                                                               //
    cout << "\n\n\nsong1 is " << song1.getTitle() << " by " << song1.getArtist() << endl; //
    cout << "song2 is " << song2.getTitle() << " by " << song2.getArtist() << endl; //
    cout << "song3 is " << song3.getTitle() << " by " << song3.getArtist() << endl; //
    cout << "song1First is " << song1First << endl;                                 //
    cout << "song2First is " << song2First << endl;                                 //
    cout << "dedicateIsFirst is " << dedicateIsFirst << endl;                       //
    cout << "uproarIsFirst is " << uproarIsFirst << endl;                           //to here

}
>>>>>>> be59f58a0e88fee5a203080fc63b7bdf9d809f6b
