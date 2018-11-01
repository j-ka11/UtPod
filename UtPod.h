//DOCUMENT HERE
//Created by Josh Kall and Chris Erattuparambil
//

#ifndef UTPOD_H
#define UTPOD_H
#include "song.h"

//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;
    void swap(SongNode *n1, SongNode *n2);
public:
    //Default constructor
    //set the memory size to MAX_MEMORY
    UtPod();

    //Constructor with size parameter
    //The user of the class will pass in a size.
    //If the size is greater than MAX_MEMORY or less than or equal to 0,
    //set the size to MAX_MEMORY.
    UtPod(int size);

    /* FUNCTION - int addSong
     * attempts to add a new song to the UtPod
         o returns a 0 if successful
         o returns -1 if not enough memory to add the song

     precondition: s is a valid Song

     input parms - reference to a song to add

     output parms - returns a 0 if successful or -1 if not enough memory
    */

    int addSong(Song const &s);


    /* FUNCTION - int removeSong
     * attempts to remove a song from the UtPod
     * removes the first instance of a song that is in the the UtPod multiple times
         o returns 0 if successful
         o returns -1 if nothing is removed


       input parms - reference to a song to remove

       output parms - returns a 0 if successful and -1 if it couldn't find the song, deletes that song's node
    */

    int removeSong(Song const &s);


    /* FUNCTION - void shuffle
     *  shuffles the songs into random order
        o will do nothing if there are less than two songs in the current list

       input parms - UtPod song list must have at least two songs

       output parms - none
    */

    void shuffle();


    /* FUNCTION - void showSongList
     * prints the current list of songs in order from first to last to standard output
     * format - Title, Artist, size in MB (one song per line)

       input parms - UtPod song list must have at least one song

       output parms - none
    */

    void showSongList();


    /* FUNCTION - void sortSongList
     *  sorts the songs in ascending order
        o will do nothing if there are less than two songs in the current list

       input parms - UtPod song list must have at least two songs

       output parms - none
    */

    void sortSongList();


    /* FUNCTION - void clearMemory
     * clears all the songs from memory

       input parms - clears dynamically allocated memory in UtPod and will do nothing if UtPod is empty

       output parms - sets head pointer to NULL
    */
    void clearMemory();


    /* FUNCTION - int getTotalMemory
     *  returns the total amount of memory in the UtPod
        o will do nothing if there are less than two songs in the current list

       input parms - must have created a UtPod object

       output parms - returns total memory in UtPod
    */

    int getTotalMemory();



    /* FUNCTION - int getRemainingMemory
     *  returns the amount of memory available for adding new songs

       input parms - must have created a UtPod object

       output parms - returns the amount of free space left to add songs
    */

    int getRemainingMemory();


    ~UtPod();

};



#endif
