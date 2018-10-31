//
// Created by Josh Kall and Chris Erattuparambil on 10/29/2018.
//
#include "UtPod.h"
#include <iostream>
#include <ctime>

using namespace std;


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
    clearMemory();
}

void UtPod::clearMemory(){
    SongNode *temp1 = songs;
    SongNode *temp2 = songs->next;
    while(temp1 != NULL){
        delete temp1;
        temp1 = temp2;
        temp2 = temp1->next;
    }
}

int UtPod::addSong(Song const &s){
    SongNode *temp;
    temp = new SongNode;
    temp->s = s;
    temp->next=songs;
    songs = temp;
}



int UtPod::removeSong(Song const &s){
    SongNode *temp = songs->next;
    SongNode *trailer = songs;
    if(songs->s == s)
    {songs=songs->next;
    }else {
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
    SongNode *temp1 = songs;
    SongNode *trailer1 = songs;
    temp1 = songs;
    int size = 0;
    while(temp1 != NULL){
        size++;
        temp1 = temp1->next;
    }
    if(size >= 2){
        size = size - 2;
    }
    temp1 = songs->next;

    unsigned int timeSeed = 42;
    srand(timeSeed);
    while(temp1 != NULL){
        int numTraverse = (rand() % size) + 1;
        SongNode *temp2 = (songs->next)->next;
        SongNode *trailer2 = songs->next;
        for(int i = 0;i < numTraverse;i++){
            temp2 = temp2->next;
            trailer2 = trailer2->next;
        }
        swap(*temp1, *temp2, *trailer1, *trailer2);
        temp1 = temp1->next;
        trailer1 = trailer1->next;
    }
    int numTraverse = (rand() % size) + 1;
    temp1 = songs;
    SongNode *temp2 = songs->next;
    SongNode *trailer2 = songs;
    for(int i = 0;i < numTraverse;i++){
        temp2 = temp2->next;
        trailer2 = trailer2->next;
    }
    songs = temp2;
    songs->next=temp1;
    trailer2->next=temp2->next;
}

void UtPod::showSongList(){
    SongNode *temp = songs;
    while(temp != NULL){
        cout << temp->s.getTitle() <<endl;
        temp = temp->next;
    }
}

void UtPod::sortSongList(){
    SongNode *temp1 = songs->next;
    SongNode *temp2 = temp1->next;
    SongNode *trailer1 = songs;
    SongNode *trailer2 = songs->next;
    while(temp1 != NULL){
        while(temp2 != NULL){
            if(temp2->s < temp1->s){
                swap(*temp1, *temp2, *trailer1, *trailer2);
            } else{
                temp2=temp2->next;
            }
        }
        temp1=temp1->next;
    }
    if(songs->s<songs->next->s)
    {
        return;
    }
    else{
        SongNode *temp3=songs->next;
        SongNode *trailer3=songs;
        while(temp3->next!=NULL)
        {
            if(songs->s>temp3->s)
            {
                temp3=temp3->next;
            }
            else
            {
                SongNode *tempHead=songs->next;
                trailer3->next=songs;
                songs->next=temp3;
                songs=tempHead;
            }
        }

    }
    return;
}

int UtPod::getRemainingMemory(){
    int memoryTotal = 0;
    SongNode *temp = songs;
    while(temp != NULL){
        memoryTotal = memoryTotal + temp->s.getSize();
        temp = temp->next;
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