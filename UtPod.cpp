//
// Created by Josh Kall and Chris Erattuparambil on 10/29/2018.
//
#include "UtPod.h"


UtPod::UtPod(){
    memSize = MAX_MEMORY;
    return;
}

UtPod::UtPod(int s)
{
   if(s<0||s>MAX_MEMORY)
   {
       memSize = MAX_MEMORY;
   }
   else
   {
       memSize=s;
   }
}

UtPod::~UtPod()
{

}


int UtPod::addSong(Song const &s){

}

void createSong(){

}

int UtPod::removeSong(Song const &s){

}

void UtPod::shuffle(){

}

void UtPod::showSongList(){

}

void UtPod::sortSongList(){

}

int UtPod::getRemainingMemory(){

}