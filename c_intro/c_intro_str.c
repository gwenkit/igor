#include <stdio.h>
#include <string.h>


int main(void)
{
    int i;

    char str1[31] = "abcdefgh";
    char str2[7];

    int sizeof_str1 = sizeof(str1);
    int sizeof_str2 = sizeof(str2);
    printf("sizeof_str1: %d, sizeof_str2: %d\n", sizeof_str1, sizeof_str2);

    for (i=0; i<sizeof_str1; i++) {
        printf("[%2d] %c (%d)\n", i, str1[i], str1[i]);
    }

    int size_to_be_copied = sizeof_str2 - 1;
    strncpy(str2, str1, size_to_be_copied);
    str2[size_to_be_copied] = '\0';
    printf("copied: ");
    puts(str2);

    printf("'%s'\n", str1);
    printf("'%s'\n", str2);

    for (i=0; i<sizeof_str2; i++) {
        printf("[%2d] %c (%d)\n", i, str2[i], str2[i]);
    }

    char str3[7] = "abcdef";
    printf("?( str2(copied) vs. str3(literal) ): %d\n", strcmp(str2, str3));

    char str4[8] = "abcdef";
    printf("?( str2(7) vs. str4(8) ): %d\n", strcmp(str2, str4));

    char str5[7] = "Abcdef";
    printf("?( str2(\"%s\") vs. str5(\"%s\") ): %d\n", str2, str5, strcmp(str2, str5));

    char str6[7] = "abcdeF";
    printf("?( str2(\"%s\") vs. str6(\"%s\") ): %d\n", str2, str6, strcmp(str2, str6));

    char str7[7] = " bcdef";
    printf("?( str2(\"%s\") vs. str7(\"%s\") ): %d\n", str2, str7, strcmp(str2, str7));

    char str8[7] = "abcde ";
    printf("?( str2(\"%s\") vs. str8(\"%s\") ): %d\n", str2, str8, strcmp(str2, str8));
    printf("?( str8(\"%s\") vs. str2(\"%s\") ): %d\n", str8, str2, strcmp(str8, str2));
    printf("?( str8(\"%s\") vs. str7(\"%s\") ): %d\n", str8, str7, strcmp(str8, str7));

    char * str9 = "ABCD" "EFGH";
    char * str0 = "ABCDEFGH";
    int sizeof_str9 = sizeof(str9);
    int sizeof_str0 = sizeof(str0);
    printf("%s (%d)\n", str9, sizeof_str9);
    printf("%s (%d)\n", str0, sizeof_str0);
    printf("?( str9(\"%s\") vs. str0(\"%s\") ): %d\n", str9, str0, strcmp(str9, str0));


    return 0;
}


