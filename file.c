#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *description;
    char *tag;
    char *location;
    int value;
    int damage;
    int armour;
} object;

object objects[1];

void load_objects()
{
  printf("Loading from file...\n");
  char line[250];
  int i = 0;
  int n;
  char *d;
  char *t;
  char *l;
  int v;
  int dam;
  int arm;

  FILE *in = fopen("objects.dat", "r");

  n = fscanf(in, "%s,%s,%s,%d,%d,%d ", d,t,l,&v,&dam,&arm);

      /*
                                objects[i].description, objects[i].tag,
                                objects[i].location, &objects[i].value, 
                                &objects[i].damage, &objects[i].armour);
       */
  //printf("File Contents: %s, %s, %s, %d, %d, %d.\n", d,t,l,v,dam,arm);
      /*
                                objects[i].description, objects[i].tag,
                                objects[i].location, objects[i].value,
                                objects[i].damage, objects[i].armour);

       */
  printf("  d = %s\n", d);
  printf("  t = %s\n", t);
  printf("  l = %s\n", l);
  printf("  v = %d\n", v);
  printf("dam = %d\n", dam);
  printf("arm = %d\n", arm);
  printf("n = %d\n", n);
  i++;
  fclose(in);

  return;
}

int main()
{
  load_objects();

  return 0;
}
