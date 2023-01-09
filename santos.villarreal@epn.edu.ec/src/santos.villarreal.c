#include <stdio.h>
#include <string.h>
#include <io.h>
#include <Windows.h>
#include "../lib/svColores.h"

//santos.villarreal@epn.edu.ec
// variable inician con sv

#define svMaxUsernameLen 100
#define svPasswordLen 100

int svLoginSantos(char *username, char *password) {
  char *svValidUsername1 = "santos.villarreal@epn.edu";
  char *svValidPassword1 = "175341599";
  char *svValidUsername2 = "teacher";
  char *svValidPassword2 = "1234";
  if ((strcmp(username, svValidUsername1) == 0 && strcmp(password, svValidPassword1) == 0) ||
      (strcmp(username, svValidUsername2) == 0 && strcmp(password, svValidPassword2) == 0)) {
    printf("¡Autenticacion exitosa!\n");
    return 1;
  } else {
    printf("¡La autenticacion falló!\n");
    return 0;
  }
}

int svMenu() {
  int choice;
  printf("\nBienvenido\nUsuario selecciona:\n");
  printf("1. Mostrar Usuario\n");
  printf("2. Barra de carga\n");
  printf("3. Combinatoria\n");
  printf("0. Salir\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  return choice;
}
void usleep(__int64 usec) 
{ 
    HANDLE timer; 
    LARGE_INTEGER ft; 

    ft.QuadPart = -(10*usec); // Convert to 100 nanosecond interval, negative value indicates relative time

    timer = CreateWaitableTimer(NULL, TRUE, NULL); 
    SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0); 
    WaitForSingleObject(timer, INFINITE); 
    CloseHandle(timer); 
}

int main(void) {
  char username[svMaxUsernameLen];
  char password[svPasswordLen];
	int i;
  int tries = 3;
  while (tries > 0) {
    printf("Usuario: ");
    scanf("%s", username);

    printf("Contraseña: ");
    scanf("%s", password);

    if (svLoginSantos(username, password)) {
      break;
    }

    printf("Inicio de sesion incorrecto. Tienes %d intentos restantes.\n", --tries);
  }

  
  if (tries == 0) {
    printf("Ha superado el número máximo de intentos.\n");
  } else 
  {
    int choice;
    while ((choice = svMenu()) != 0) {
      switch (choice) {
        case 1:
          printf("\t CEDULA: 175341599 \n\t CORREO: SANTOS.VILLARREAL@EPN.EDU.EC \n\t NOMBRE: santos misael villarreal vasconez \n");
          break;
        case 2:
          for (i = 0; i <= 28; i++) 
    {
        printf("\r[ ");
        int j;
        for (j = 0; j < i; j++) 
        {
            printf("=");
        }
        for (j = i; j < 28; j++) 
        {
            printf(" ");
        }
        printf(" ] %d%%\t Loading %d of 28 santos.villarreal@epn.edu.ec\r", (int)(i / 28.0 * 100.0), i);
    
        usleep(100000);
        fflush(stdout);
        }
          printf("\n");
          break;
        case 3:
          printf("Perdon no profe no pude hacer :c\n");
          break;
        default:
          printf("Respuesta invalida\n");
          break;
      }
    }
  }

  return 0;
}

