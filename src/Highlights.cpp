#include "../include/Highlights.h"

Highlights &operator++(Highlights &highlighted, int) {
  const int i = int(highlighted) + 1;
  if (i >= 5) return highlighted;
  highlighted = Highlights(i);
  return highlighted;
}

Highlights &operator--(Highlights &highlighted, int) {
  const int i = int(highlighted) - 1;
  if (i < 1) return highlighted;
  highlighted = Highlights(i);
  return highlighted;
}