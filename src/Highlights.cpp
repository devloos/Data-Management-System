#include "../include/Highlights.h"

Highlights &operator++(Highlights &highlighted, int MaxSize) {
  const int i = int(highlighted) + 1;
  if (i >= MaxSize) return highlighted;
  highlighted = Highlights(i);
  return highlighted;
}

Highlights &operator--(Highlights &highlighted, int) {
  const int i = int(highlighted) - 1;
  if (i < 1) return highlighted;
  highlighted = Highlights(i);
  return highlighted;
}