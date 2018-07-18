#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *description;
    char *tag;
    char *location;
    int value;
    int damage;
    int armour;
} object;

object objects[100];

void load_objects()
{
  printf("Loading from file...\n");
  char line[250];
  char description[200];
  char tag[15];
  char location[15];
  char value[10];
  char damage[10];
  char armour[10];

  int i = 0;
  int n;

  FILE *in = fopen("objects.dat", "r");

  while (fgets(line, sizeof(line), in) != NULL) {
    strcpy(description, strtok(line, ",\n"));
    strcpy(tag, strtok(NULL, ",\n"));
    strcpy(location, strtok(NULL, ",\n"));
    strcpy(value, strtok(NULL, ",\n"));
    strcpy(damage, strtok(NULL, ",\n"));
    strcpy(armour, strtok(NULL, ",\n"));
    
    objects[i].description = description;
    objects[i].tag = tag;
    objects[i].location = location;
    objects[i].value = atoi(value);
    objects[i].damage = atoi(damage);
    objects[i].armour = atoi(armour);

    printf("%s,%s,%s,%d,%d,%d.\n", objects[i].description,
        objects[i].tag, objects[i].location, objects[i].value, 
        objects[i].damage, objects[i].armour);
    i++;
  }
  fclose(in);

  return;
}

int main()
{
  load_objects();

  return 0;
}
