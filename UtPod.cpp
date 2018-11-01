//
// Created by Josh Kall and Chris Erattuparambil on 10/29/2018.
//
#include "UtPod.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


UtPod::UtPod() {
    songs = NULL;
    memSize = MAX_MEMORY;
    return;
}

UtPod::UtPod(int s) {
    songs = NULL;
    if (s < 0 || s > MAX_MEMORY) {
        memSize = MAX_MEMORY;
    } else {
        memSize = s;
    }
}

UtPod::~UtPod() {
    clearMemory();
}

void UtPod::clearMemory() {
    if(songs == NULL){
        return;
    }
    SongNode *temp1 = songs;
    SongNode *temp2 = songs->next;
    while (temp1 != NULL) {
        delete temp1;
        temp1 = temp2;
        if(temp2 == NULL){
            songs = NULL;
            return;
        }
        temp2 = temp1->next;
    }
    songs = NULL;
}

int UtPod::addSong(Song const &s) {
    if (getRemainingMemory() >= s.getSize()) {
        SongNode *temp;
        temp = new SongNode;
        temp->s = s;
        temp->next = songs;
        songs = temp;
        return SUCCESS;
    } else {
        return NO_MEMORY;
    }
}


int UtPod::removeSong(Song const &s) {
    if (songs == NULL) {
        return NOT_FOUND;
    } else if(songs->next == NULL){
        if(songs->s == s){
            delete songs;
            songs = NULL;
            return SUCCESS;
        }else if(songs->s != s){
            return NOT_FOUND;
        }
    } else if (songs->next != NULL) {
        SongNode *temp = songs->next;
        SongNode *trailer = songs;
        if (songs->s == s) {
            songs = songs->next;
        } else {
            while (((temp->s > s) || (temp->s < s)) && (temp != NULL)) {
                temp = temp->next;
                trailer = trailer->next;
            }
            if (temp == NULL) {
                return NOT_FOUND;
            } else {
                SongNode *newTemp = temp;
                trailer->next = temp->next;
                delete newTemp;
                return SUCCESS;
            }
        }
    } else if (songs->s == s) {
        delete songs;
        return SUCCESS;
    }
}

void UtPod::shuffle() {
    if (songs == NULL) {
        cout << "there are no songs when trying to shuffle" << endl;
        return;
    } else if (songs->next == NULL) {
        cout << "there is one song when trying to shuffle" << endl;
        return;
    } else if(songs->next->next==NULL){
        SongNode *twoSongs=songs->next;
        twoSongs->next=songs;
        songs->next=NULL;
        songs=twoSongs;
    }else {
        SongNode *temp1;
        temp1 = songs;
        int size = 0;
        while (temp1 != NULL) {
            size++;
            temp1 = temp1->next;
        }
        if (size >= 2) {
            size = size - 2;
        }
        temp1 = songs;

        while (temp1 != NULL){

            int numTraverse = (rand() % size) + 1;
            SongNode *temp2 = songs->next;;
            for (int i = 0; i < numTraverse; i++) {
                temp2 = temp2->next;
            }
            swap(temp1,temp2);
            temp1 = temp1->next;
        }

    }
}

void UtPod::showSongList() {
    SongNode *temp = songs;
    while (temp != NULL) {
        cout << temp->s.getTitle() << ", " << temp->s.getArtist() << ", " << temp->s.getSize() << endl;
        temp = temp->next;
    }
}

void UtPod::sortSongList() {
    if(songs == NULL){
        cout << "there are no songs when trying to sort" << endl;
        return;
    }else if(songs->next == NULL){
        cout << "there is one song when trying to sort" << endl;
    }else{
        SongNode *temp1 = songs;
        while(temp1->next != NULL){
            SongNode *temp2 = temp1->next;
            while(temp2 != NULL){
                if(temp1->s > temp2->s){
                    swap(temp1, temp2);
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }
}

int UtPod::getTotalMemory() {
    if(songs == NULL){
        return 0;
    }else{
        SongNode *temp = songs;
        int totalMemory = 0;
        while(temp != NULL){
            totalMemory = totalMemory + temp->s.getSize();
            temp = temp->next;
        }
        return totalMemory;
    }
}

int UtPod::getRemainingMemory() {
    int memoryTotal = 0;
    SongNode *temp = songs;
    while (temp != NULL) {
        memoryTotal = memoryTotal + temp->s.getSize();
        temp = temp->next;
    }
    return (memSize - memoryTotal);
}

void UtPod::swap(SongNode *n1, SongNode *n2) {
    string artist = n1->s.getArtist();
    string title = n1->s.getTitle();
    int size = n1->s.getSize();
    n1->s.setArtist(n2->s.getArtist());
    n1->s.setTitle(n2->s.getTitle());
    n1->s.setSize(n2->s.getSize());
    n2->s.setArtist(artist);
    n2->s.setTitle(title);
    n2->s.setSize(size);
}