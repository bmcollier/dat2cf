#include <stdio.h>

int main(int argc, char **argv)
{
    printf("dat2cf: Convert 8-bit images to 16-bit images\n");
    printf("---------------------------------------------\n");
    printf("For use with retro adaptors and peripheral technology such as the RetroClinic Datacentre.\n\n");
    if(argc==3) {
        printf("Input file: %s\n", argv[1]);
        printf("Output file: %s\n\n", argv[2]);
    } else {
        printf("Too few command line parameters. Expected 2 parameters: Input file and output files\n");
        printf("Usage: dat2cf <input file path> <output file path>\n");
        return 1;
    }
    FILE *fp = fopen(argv[1], "rb");
    FILE *ofp = fopen(argv[2],"wb");
    if(fp && ofp)
    {
        printf("Commencing with conversion....\n");
        unsigned char buffer[4096];
        size_t sz;
        //int line = 0;
        long writeByte = 0;
        int blank = 0;
        while ((sz = fread(buffer, 1, sizeof(buffer), fp)) > 0)
        {
            for(int i = 0; i < sz; i++)
            {
                //printf("%c", buffer[i]);
                fwrite(&buffer[i], 1, 1, ofp);
                writeByte++;
                fwrite(&blank, 1,1, ofp);
                writeByte++;
                //line++;
                //if((line % 8) == 0)
                //    printf("\n");
            }
        }
        printf("%ld bytes written.\n", writeByte);
    } else {
        if(!fp) {
            printf("Error opening input file. Please check path and try again.\n");
        }
        else {
            printf("Error opening files.\n");
        }
    }

    return 0;
}

