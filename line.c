#include"line.h"
#include<stdlib.h>
#include<curses.h>
#include<stdlib.h>
#include<stdio.h>
void initq(line *s){
    s->link = (point *)calloc(1,sizeof(point));
    //s->link->element = (istack *)calloc(1,sizeof(istack));
    inits(&(s->link->element));
    s->link->head = NULL;
    s->link->tail = NULL;
    //printw("%p\n",s->link->tail);
    //refresh();
    s->front = s->link;
    s->lines = 0;
}
void enqueue(line *s){
    point *temp =  (point *)calloc(1,sizeof(point));
    temp->head = s->link;
    temp->tail = NULL;
    //printw("1\n");
    //refresh();
    inits(&(temp->element));
    s->link->tail = temp;
    s->link = temp;
    s->lines++;


}
void enqueue_pos(line *l, int a){
    point *newnode = (point *)calloc(1,sizeof(point));
    inits(&(newnode->element));
    if(l->front == NULL){
        l->front = newnode;
        l->link = newnode;
        l->lines++;
        return;
    }
    point* temp = l->front;
    int i = 0;
    for(; i < a && temp->tail != NULL; i++)
        temp = temp->tail;
    if(temp->head != NULL){
        temp->head->tail = newnode;
        newnode->head = temp->head;
    } else {
        l->front = newnode;
        newnode->head = NULL;
    }
    newnode->tail = temp;
    temp->head = newnode;
    l->lines++;
    return;
}
void dequeue(line *s){
    if(s->link == NULL)
        return;
    point *temp = s->link;
    if(s->link->head != NULL){
        s->link->head->tail = NULL;
        s->link = s->link->head;
    } else {
        s->link = NULL;
        s->front = NULL;
    }
    if(s->lines > 0)
        s->lines--;
    free(temp);
    return;
}
void dequeueloc(line *s,int x){
    if(s->front == NULL)
        return;
    point* temp = s->front;
    int i;
    for(i = 0; i < x && temp->tail != NULL; i++)
        temp = temp->tail;
    
    if(temp->tail == NULL){
        dequeue(s);
        return;
    }
    if(temp->head != NULL){
        temp->head->tail = temp->tail;
    } else {
        s->front = temp->tail;
    }
    if(temp->tail != NULL){
        temp->tail->head = temp->head;
    }
    if(s->lines > 0)
        s->lines--;
    free(temp);
    return;
}
int isEmptyq(line *s){
    if(s == NULL || s->link == NULL || s->front == NULL)
        return 1;
    return 0;
}
int ipeepq(line *s){
    if(s == NULL) return 0;
    return s->lines;
}

