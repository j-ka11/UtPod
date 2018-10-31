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
    SongNode *temp;
    temp=songs;
    songs->s=s;
    songs->next=temp;
}



int UtPod::removeSong(Song const &s){
    SongNode *temp;
    SongNode *trailer;
    if(songs->s == s)
    {songs=songs->next;
    }else {
        temp = songs->next;
        trailer = songs;
        while (((temp->s > s) || (temp->s < s)) && (temp->next != NULL)) {
            temp = temp->next;
            trailer = trailer->next;
        }
        trailer->next = temp->next;
        if (temp->next == NULL) {
            return NOT_FOUND;
        }else{
            return SUCCESS;
        }
    }
}

void UtPod::shuffle(){

}

void UtPod::showSongList(){

}

void UtPod::sortSongList(){

}

int UtPod::getRemainingMemory(){
    int memoryTotal = 0;
    SongNode *temp;
    temp = songs;
    while(temp != NULL){
        memoryTotal = memoryTotal + temp->s.getSize();
    }
    return (memSize - memoryTotal);
}

void UtPod::swap(SongNode &n1, SongNode &n2, SongNode &trailer1, SongNode &trailer2)
{
    trailer1.next = &n2;
    trailer2.next = &n1;
    SongNode *temp;
    temp = n1.next;
    n1.next = n2.next;
    n2.next = temp;
}