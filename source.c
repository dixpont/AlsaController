#include <stdio.h>
#include <stdlib.h>	//to use system()

int main() {

    FILE *fp;
    char s;

    printf("All available cards: \n\n");

    fp = fopen("/proc/asound/cards", "r");
    while((s=fgetc(fp))!=EOF) {
        printf("%c",s);
    }
    fclose(fp);

    int card;
    printf ("Choose a sound card: ");
    scanf ("%d", &card);
    
    remove("asound.conf");
    fp = fopen("/etc/asound.conf", "w");
    fprintf(fp,"defaults.pcm.card %d\n", card);
    fprintf(fp,"defaults.ctl.card %d\n", card);

    fclose(fp);

    system("alsactl restore");

    printf("Changes made succesfully!\n");

}
