#ifndef HIGHLIGHTS_H_
#define HIGHLIGHTS_H_

enum Highlights { CreateCollection = 1, ResetCollection, RemoveCollection, Exit };

Highlights &operator++(Highlights &highlighted, int);
Highlights &operator--(Highlights &highlighted, int);

#endif  // HIGHLIGHTS_H_