#include"sort.h"
#include<algorithm>
void sortByArea(std::vector<Shape*>::iterator front,std::vector<Shape*>::iterator end)
{
   std::sort(front,end,areaAscendingComparison);  //test
}
bool areaAscendingComparison(Shape *a, Shape *b)
{
  return a->area() < b->area();
}
