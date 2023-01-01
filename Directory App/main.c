#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // Vars:
  int sort;
  char name[] = "Name";
  char last_name[] = "Last Name";
  char number[] = "Number";
  char directory[25][3][40]; // 2 dimensional string directory array
  int numberOfOnes = 0;
  int x = 0;
  printf("Enter 0 when there are no more people to register!\n");
  // rehbere ekleme işlemi bitene kadar döngüye alır.
  while (numberOfOnes <= 25) {
    printf("Name : ");
    scanf("%s", directory[numberOfOnes][x]);
    x++;
    if (directory[numberOfOnes][x - 1][0] ==
        48) { // Kullanıcı 0 girdiyse rehbere ekleme işlemini durdurur.
      printf("There are no people left to add to the directory...\n");
      directory[numberOfOnes][x][0] = NULL;
      break;
    }
    printf("Last Name : ");
    scanf("%s", directory[numberOfOnes][x]);
    x++;
    printf("Number : ");
    scanf("%s", directory[numberOfOnes][x]);
    x = 0;
    numberOfOnes++;
  }
  if (numberOfOnes == 26) {
    printf("The number of people has reached 25! Sorry, you can't add another "
           "person...\n");
  }

  printf("Sort your directory according to what (name: 0, surname: 1, number: "
         "2) : ");
  //
  while (1) { // Kullanıcı geçersiz işlem girerse yeniden işlem girebilsin diye
              // döngüye alır.
    scanf("%d", &sort);
    if (sort == 0) {
      char tmp1[10];
      char tmp2[10];
      char tmp3[10];
      //İsme göre kabarcık sıralama
      for (int i = 0; i < numberOfOnes; i++) {
        for (int j = 0; j < numberOfOnes - 1; j++) {
          if (strcmp(directory[j][0], directory[i][0]) > 0) {
            strcpy(tmp1, directory[i][0]);
            strcpy(tmp2, directory[i][1]);
            strcpy(tmp3, directory[i][2]);
            strcpy(directory[i][0], directory[j][0]);
            strcpy(directory[i][1], directory[j][1]);
            strcpy(directory[i][2], directory[j][2]);
            strcpy(directory[j][0], tmp1);
            strcpy(directory[j][1], tmp2);
            strcpy(directory[j][2], tmp3);
          }
        }
      }
      break;
    } else if (sort == 1) {
      char tmp1[10];
      char tmp2[10];
      char tmp3[10];
      // Soyisme göre kabarcık sıralama
      for (int i = 0; i < numberOfOnes; i++) {
        for (int j = 0; j < numberOfOnes - 1; j++) {
          if (strcmp(directory[j][1], directory[i][1]) > 0) {
            strcpy(tmp1, directory[i][0]);
            strcpy(tmp2, directory[i][1]);
            strcpy(tmp3, directory[i][2]);
            strcpy(directory[i][0], directory[j][0]);
            strcpy(directory[i][1], directory[j][1]);
            strcpy(directory[i][2], directory[j][2]);
            strcpy(directory[j][0], tmp1);
            strcpy(directory[j][1], tmp2);
            strcpy(directory[j][2], tmp3);
          }
        }
      }
      break;
    } else if (sort == 2) {
      char tmp1[10];
      char tmp2[10];
      char tmp3[10];
      // Numaraya göre kabarcık sıralama.
      for (int i = 0; i < numberOfOnes; i++) {
        for (int j = 0; j < numberOfOnes - 1; j++) {
          if (strcmp(directory[j][2], directory[i][2]) > 0) {
            strcpy(tmp1, directory[i][0]);
            strcpy(tmp2, directory[i][1]);
            strcpy(tmp3, directory[i][2]);
            strcpy(directory[i][0], directory[j][0]);
            strcpy(directory[i][1], directory[j][1]);
            strcpy(directory[i][2], directory[j][2]);
            strcpy(directory[j][0], tmp1);
            strcpy(directory[j][1], tmp2);
            strcpy(directory[j][2], tmp3);
          }
        }
      }
      break;
    } else {
      printf("Please enter a valid operation!");
      continue;
    }
  }
  printf("Name   Last Name   Number\n");
  // Rehberi yazdırır.
  for (int i = 0; i < numberOfOnes; i++) {
    printf("| %s |", directory[i][0]);
    printf("| %s |", directory[i][1]);
    printf("| %s |\n", directory[i][2]);
  }
  while (1) { // Kullanıcı istediği kadar işlem yapabilmesi için döngüye alır.
    int action;
    printf("Add a new registry : 1\nReaching a registry : 2\nChancing data : "
           "3\nDeleting Registry : 4\nExit : 5\n");
    printf("The action you want to take : ");
    scanf("%d", &action);
    if (action == 1) {          // Kullanıcı yeni kişi eklemek istiyor.
      if (numberOfOnes <= 25) { // Kişi sayısının 25 dan küçük olduğuna bakıyor.
                                // Büyükse yeni kişi eklemez
        // Rehbere yeni kişi ekler.
        printf("Name of one who is you want to add : ");
        scanf("%s", directory[numberOfOnes][0]);
        printf("Last name of one who is you want to add : ");
        scanf("%s", directory[numberOfOnes][1]);
        printf("Number of one who is you want to add : ");
        scanf("%s", directory[numberOfOnes][2]);
        numberOfOnes++;
      } else {
        printf("There is no place to add a new registry.!\n");
      }
    } else if (action == 2) {
      while (1) {
        int action2;
        printf("Which way do you want to reach(name : 0, last name : 1, "
               "number: 2) : ");
        scanf("%d", &action2);
        if (action2 == 0) {
          char name[20];
          int myBool = 0;
          int whichPerson;
          printf("Kayıttaki name : ");
          scanf("%s", name);
          //İsim bilgisi ile rehberdeki kişiyi bulur.
          for (int i = 0; i < numberOfOnes; i++) {
            if (strcmp(name, directory[i][0]) == 0) {
              printf("The person you calles is found : \n");
              printf("| %s | | %s | | %s |", directory[i][0], directory[i][1],
                     directory[i][2]);
              myBool = 1;
              whichPerson = i;
              break;
            }
          }
          if (myBool == 0) {
            printf("The person you called could not found. Please try again...\n");
          } else {
            int action3;
            printf("What do you want to make to registry(Changing data : 3, Deleting Registry : 4) : ");
            scanf("%d", &action3);
            if (action3 == 3) {
              char newName[20];
              char newLastName[20];
              char newNumber[20];
              printf("New Name : ");
              scanf("%s", newName);
              printf("New Last Name : ");
              scanf("%s", newLastName);
              printf("New Number : ");
              scanf("%s", newNumber);
              // Yeni veriler ile değiştirme işlemi yapar.
              strcpy(directory[whichPerson][0], newName);
              strcpy(directory[whichPerson][1], newLastName);
              strcpy(directory[whichPerson][2], newNumber);
              printf("Registry was changed...\n");
              printf("| %s | | %s | | %s |\n", directory[whichPerson][0],
                     directory[whichPerson][1], directory[whichPerson][2]);
            } else if (action3 == 4) {
              // Kişiyi siler ve sıralamyı yeniden inşa eder.
              for (int i = whichPerson; i < numberOfOnes - 1; i++) {
                strcpy(directory[i][0], directory[i + 1][0]);
                strcpy(directory[i][1], directory[i + 1][1]);
                strcpy(directory[i][2], directory[i + 1][2]);
              }
              // Bir kişi silindiği için en sonda aynı kişiden iki tane olur.
              // 2'nci yi de siler.
              for (int i = 0; i < sizeof(directory[numberOfOnes][0]); i++) {
                directory[numberOfOnes - 1][0][i] = NULL;
              }
              for (int i = 0; i < sizeof(directory[numberOfOnes][1]); i++) {
                directory[numberOfOnes - 1][0][i] = NULL;
              }
              for (int i = 0; i < sizeof(directory[numberOfOnes][2]); i++) {
                directory[numberOfOnes - 1][0][i] = NULL;
              }
              numberOfOnes--;
              printf("Person is deleted...\n");
            }
            break;
          }

        } else if (action2 == 1) {
          char lastName[20];
          int myBool = 0;
          int whichPerson;
          printf("Last Name : ");
          scanf("%s", lastName);
          for (int i = 0; i < numberOfOnes; i++) {
            if (strcmp(lastName, directory[i][1]) == 0) {
              printf("The person you called is found : \n");
              printf("| %s | | %s | | %s |", directory[i][0], directory[i][1],
                     directory[i][2]);
              myBool = 1;
              whichPerson = i;
              break;
            }
          }
          if (myBool == 0) {
            printf("The person you called could not found. Please try again...\n");
          } else {
            int action3;
            printf("What do you want to make to registry(Changing data : 3, Deleting Registry : 4) : ");
            scanf("%d", &action3);
            if (action3 == 3) {
              char newName[20];
              char newLastName[20];
              char newNumber[20];
              printf("New Name : ");
              scanf("%s", newName);
              printf("New Last Name : ");
              scanf("%s", newLastName);
              printf("New Number : ");
              scanf("%s", newNumber);
              strcpy(directory[whichPerson][0], newName);
              strcpy(directory[whichPerson][1], newLastName);
              strcpy(directory[whichPerson][2], newNumber);
              printf("Registry was changed...\n");
              printf("| %s | | %s | | %s |\n", directory[whichPerson][0],
                     directory[whichPerson][1], directory[whichPerson][2]);
            } else if (action3 == 4) {
              for (int i = whichPerson; i < numberOfOnes - 1; i++) {
                strcpy(directory[i][0], directory[i + 1][0]);
                strcpy(directory[i][1], directory[i + 1][1]);
                strcpy(directory[i][2], directory[i + 1][2]);
              }

              for (int i = 0; i < sizeof(directory[numberOfOnes][0]); i++) {
                directory[numberOfOnes - 1][0][i] = NULL;
              }
              for (int i = 0; i < sizeof(directory[numberOfOnes][1]); i++) {
                directory[numberOfOnes - 1][0][i] = NULL;
              }
              for (int i = 0; i < sizeof(directory[numberOfOnes][2]); i++) {
                directory[numberOfOnes - 1][0][i] = NULL;
              }
              numberOfOnes--;
              printf("Person is deleted...\n");
            }
            break;
          }
        } else if (action2 == 2) {
          char number[20];
          int myBool = 0;
          int whichPerson;
          printf("Number : ");
          scanf("%s", number);
          for (int i = 0; i < numberOfOnes; i++) {
            if (strcmp(number, directory[i][2]) == 0) {
              printf("The person you called is found : \n");
              printf("| %s | | %s | | %s |", directory[i][0], directory[i][1],
                     directory[i][2]);
              myBool = 1;
              whichPerson = i;
              break;
            }
          }
          if (myBool == 0) {
            printf("The person you called could not found. Please try again...\n");
          } else {
            int action3;
            printf("What do you want to make to registry(Changing data : 3, Deleting Registry : 4) : ");
            scanf("%d", &action3);
            if (action3 == 3) {
              char newName[20];
              char newLastName[20];
              char newNumber[20];
              printf("New Name : ");
              scanf("%s", newName);
              printf("New Last Name : ");
              scanf("%s", newLastName);
              printf("New Number : ");
              scanf("%s", newNumber);
              strcpy(directory[whichPerson][0], newName);
              strcpy(directory[whichPerson][1], newLastName);
              strcpy(directory[whichPerson][2], newNumber);
              printf("Registry was changed...\n");
              printf("| %s | | %s | | %s |\n", directory[whichPerson][0],
                     directory[whichPerson][1], directory[whichPerson][2]);
            } else if (action3 == 4) {
              for (int i = whichPerson; i < numberOfOnes - 1; i++) {
                strcpy(directory[i][0], directory[i + 1][0]);
                strcpy(directory[i][1], directory[i + 1][1]);
                strcpy(directory[i][2], directory[i + 1][2]);
              }

              for (int i = 0; i < sizeof(directory[numberOfOnes][0]); i++) {
                directory[numberOfOnes - 1][0][i] = NULL;
              }
              for (int i = 0; i < sizeof(directory[numberOfOnes][1]); i++) {
                directory[numberOfOnes - 1][0][i] = NULL;
              }
              for (int i = 0; i < sizeof(directory[numberOfOnes][2]); i++) {
                directory[numberOfOnes - 1][0][i] = NULL;
              }
              numberOfOnes--;
              printf("Person is deleted...\n");
            }
            break;
          }
        }
      }
    } else if (action == 3) {
      printf("In order to do this, you need to enter the 2nd process and access the person....\n");
    } else if (action == 4) {
      printf("In order to do this, you need to enter the 2nd process and access the person....\n");
    } else if (action == 5) {
      printf("Exit...");
      break;
    } else {
      printf("Please enter a valid action!...\n");
    }
    // Rehberi yazdırır.
    printf("\n");
    for (int i = 0; i < numberOfOnes; i++) {
      printf("| %s |", directory[i][0]);
      printf("| %s |", directory[i][1]);
      printf("| %s |\n", directory[i][2]);
    }
  }
  return 0;
}