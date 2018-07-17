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

  FILE *in;
  in = fopen("objects.dat", "r");

  fscanf(in, "%s,%s,%s,%d,%d,%d", objects[i].description, objects[i].tag,
                                objects[i].location, &objects[i].value, 
                                &objects[i].damage, &objects[i].armour);
  printf("File Contents: %s, %s, %s, %d, %d, %d.\n", 
                                objects[i].description, objects[i].tag,
                                objects[i].location, objects[i].value,
                                objects[i].damage, objects[i].armour);
  i++;
  fclose(in);

  return;
}

int main()
{
  load_objects();

  return 0;
}
