#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void header();

void F1();

void F2();

void F3(int, int*, char array[][20], char array1[][20], char array2[][50], double* );

void F4(int*, char Name[][20], char Symbol[][20], char ChemicalGroup[][50], double*);

void F5(int, int, char*, int, int, int*, char Name[][20], char Symbol[][20], char ChemicalGroup[][50], double*);

int binary_search(int*, int, int);

int linear_search(char array[][20], int, char*);

int input(int, int);

int main(){
    int repeat;

    int AtomicNumber[118]={0};
    for (int i=0; i<118; i++){
        AtomicNumber[i]=i+1;
    }
    char Name[118][20]={"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon",
        "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium",
        "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc",
        "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium",
        "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin",
        "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
        "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium",
        "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury",
        "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium",
        "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium",
        "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium",
        "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"};

    char Symbol[118][20]={"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
        "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
        "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
        "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
        "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
        "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
        "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
        "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
        "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
        "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
        "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
        "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

    char ChemicalGroup[118][50]={"Nonmetal", "Noble gas", "Alkali metal", "Alkaline earth metal", "Metalloid",
        "Nonmetal", "Nonmetal", "Nonmetal", "Halogen", "Noble gas",
        "Alkali metal", "Alkaline earth metal", "Post-Transition Metal", "Metalloid", 
        "Nonmetal", "Nonmetal", "Halogen", "Noble gas", "Alkali metal",
        "Alkaline earth metal", "Transition metal", "Transition metal", 
        "Transition metal", "Transition metal", "Transition metal",
        "Transition metal", "Transition metal", "Transition metal",
        "Transition metal", "Transition metal", "Post-transition metal",
        "Metalloid", "Metalloid", "Nonmetal", "Halogen", "Noble gas",
        "Alkali metal", "Alkaline earth metal", "Transition metal", 
        "Transition metal", "Transition metal", "Transition metal", 
        "Transition metal", "Transition metal", "Transition metal", 
        "Transition metal", "Transition metal", "Transition metal", 
        "Post-transition metal", "Post-transition metal", "Metalloid", 
        "Metalloid", "Halogen", "Noble gas", "Alkali metal", 
        "Alkaline earth metal", "Lanthanide", "Lanthanide", "Lanthanide",
        "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", 
        "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", 
        "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide",
        "Transition metal", "Transition metal", "Transition metal", 
        "Transition metal", "Transition metal", "Transition metal", 
        "Transition metal", "Transition Metal", "Transition metal",
        "Post-transition metal", "Post-transition metal", "Post-Transition Metal", 
        "Metalloid", "Halogen", "Noble Gas", "Alkali Metal", 
        "Alkaline Earth Metal", "Actinide", "Actinide", "Actinide", "Actinide", 
        "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", 
        "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", 
        "Actinide", "Transition Metal", "Transition metal", 
        "Transition metal", "Transition metal", "Transition metal", 
        "Transition metal", "Transition metal", "Post-transition metal", 
        "Transition metal", "Post-transition metal", "Post-transition metal",
        "Post-Transition Metal", "Post-Transition Metal", "Halogen", "Noble Gas" };


    double AtomicMass[118]={1.0080, 4.00260, 7.0, 9.012183, 10.81, 12.011, 14.007, 15.9999, 18.99840316, 20.180,
        22.9897693, 24.305, 26.981538, 28.085, 30.97376200, 32.07, 35.45, 39.9, 39.0983, 40.08,
        44.95591, 47.867, 50.9415, 51.996, 54.93804, 55.84, 58.933195, 58.693, 63.55, 65.4,
        69.723, 72.63, 74.92159, 78.97, 79.90, 83.80, 85.468, 87.62, 88.90584, 91.22,
        92.90637, 95.95, 96.90636, 101.1, 102.9055, 106.42, 107.868, 112.41, 114.818, 118.71,
        121.760, 127.6, 126.9045, 131.29, 132.9054520, 137.33, 138.9055, 140.116, 140.90766, 144.24,
        144.91276, 150.4, 151.964, 157.25, 158.92535, 162.500, 164.93033, 167.26, 168.93422, 173.05,
        174.9667, 178.49, 180.9479, 183.84, 186.207, 190.2, 192.22, 195.08, 196.96657, 200.59,
        204.3833, 207.0, 208.98040, 208.98243, 209.98715, 222.01758, 223.01973, 226.02541, 227.02775, 232.038,
        231.03588, 238.0289, 237.048172, 244.06420, 243.061380, 247.07035, 247.07031, 251.07959, 252.0830, 257.09511,
        258.09843, 259.10100, 266.120, 267.122, 268.126, 269.128, 270.133, 269.1336, 277.154, 282.166, 282.169,
        286.179, 286.182, 290.192, 290.196, 293.205, 294.211, 295.216};

    do {
        system("clear");
        F1();
        int n1=input(1,3);

        if (n1==1){
            system("clear");
            F2();
            int n2=input(1,3);
            system("clear");
            F3(n2, AtomicNumber, Name, Symbol, ChemicalGroup, AtomicMass);
            printf("\n Type 1 to return to the first window or 0 to terminate the application: ");
            repeat=input(0,1);
            printf("\n");
        } else if (n1==2){
            system("clear");
            F4(AtomicNumber, Name, Symbol, ChemicalGroup, AtomicMass);
            
            printf("\n Type 1 to return to the first window or 0 to terminate the application: ");
            repeat=input(0,1);
            printf("\n");
        


        }else{
            exit(1);
        }
    } while (repeat==1);
    return 0;
}


void header(){
    printf(" |--------------------------|\n");
    printf(" |Periodic Table of Elements|\n");
    printf(" |--------------------------|\n\n");
}

void F1(){
    header();

    printf(" 1. Search for individual elements\n");
    printf(" 2. Search for group of elements\n");
    printf(" 3. Terminate application\n\n");

    printf(" Type your selection (1, 2 or 3): ");

}

void F2(){
    header();

    printf(" Individual element search, based on:\n");
    printf(" 1. Atomic number\n");
    printf(" 2. Name\n");
    printf(" 3. Symbol\n\n");

    printf(" Type your selection (1, 2 or 3): ");

}

void F3(int n, int AtomicNumber[], char Name[][20], char Symbol[][20], char ChemicalGroup[][50], double AtomicMass[]){

    if(n==1){
        printf(" Provide element atomic number: ");
        int n1=input(1,118);
        int index=binary_search(AtomicNumber, 118, n1);

        printf("\n");
        header();

        printf(" Element description\n");
        printf(" 1. Atomic number: %d\n", n1);
        printf(" 2. Name: %s\n", Name[index]);
        printf(" 3. Symbol: %s\n", Symbol[index]);
        printf(" 4. Chemical group block: %s\n", ChemicalGroup[index]);
        printf(" 5. Atomic mass: %.6lf\n", AtomicMass[index]);
    
    } else if (n==2){
        char n1[11];
        int index;
        do{
            printf(" Provide element Name: ");
            scanf("%s", n1);
            index=linear_search(Name, 118, n1);
            if (index==-1){
                printf(" The element was not found or the input was incorrect! Please try again.\n");
                while (getchar()!='\n');
            } else {
                break;
            }

        } while(1);

        printf("\n");
        header();

        printf(" Element description\n");
        printf(" 1. Atomic number: %d\n", AtomicNumber[index]);
        printf(" 2. Name: %s\n", n1);
        printf(" 3. Symbol: %s\n", Symbol[index]);
        printf(" 4. Chemical group block: %s\n", ChemicalGroup[index]);
        printf(" 5. Atomic mass: %.6lf\n", AtomicMass[index]);
    
    } else{
        char n1[3];
        int index;
        do{
            printf(" Provide element Symbol: ");
            scanf("%s", n1);
            index=linear_search(Symbol, 118, n1);
            if (index==-1){
                printf(" The element was not found or the input was incorrect! Please try again.\n");
                while (getchar()!='\n');
            } else {
                break;
            }

        } while(1);

        printf("\n");
        header();

        printf(" Element description\n");
        printf(" 1. Atomic number: %d\n", AtomicNumber[index]);
        printf(" 2. Name: %s\n", Name[index]);
        printf(" 3. Symbol: %s\n", n1);
        printf(" 4. Chemical group block: %s\n", ChemicalGroup[index]);
        printf(" 5. Atomic mass: %.6lf\n", AtomicMass[index]);

    }       
}

void F4(int AtomicNumber[], char Name[][20], char Symbol[][20], char ChemicalGroup[][50], double AtomicMass[]){

    printf("\n");
    header();

    printf("Group of elements search, define criteria:");
    printf("\n 1. Minimum atomic number: ");
    int n1=input(0,118);
    printf(" 2. Maximum atomic number: ");
    int n2=input(0,118);
    printf(" 3. Chemical group block: ");
    char n3[30];
    scanf("%s", n3);
    printf(" 4. Minimum atomic mass: ");
    int n4=input(0,1000);
    printf(" 5. Maximum atomic mass: ");
    int n5=input(0,1000);

    system("clear");
    F5(n1, n2, n3, n4, n5, AtomicNumber, Name, Symbol, ChemicalGroup, AtomicMass);




}

void F5(int n1, int n2, char n3[], int n4, int n5, int AtomicNumber[], char Name[][20], char Symbol[][20], char ChemicalGroup[][50], double AtomicMass[]){
    char table[118][10]={"1:H", "2:He", "3:Li", "4:Be", "5:B", "6:C", "7:N", "8:O", "9:F", "10:Ne",
        "11:Na", "12:Mg", "13:Al", "14:Si", "15:P", "16:S", "17:Cl", "18:Ar", "19:K", "20:Ca",
        "21:Sc", "22:Ti", "23:V", "24:Cr", "25:Mn", "26:Fe", "27:Co", "28:Ni", "29:Cu", "30:Zn",
        "31:Ga", "32:Ge", "33:As", "34:Se", "35:Br", "36:Kr", "37:Rb", "38:Sr", "39:Y", "40:Zr",
        "41:Nb", "42:Mo", "43:Tc", "44:Ru", "45:Rh", "46:Pd", "47:Ag", "48:Cd", "49:In", "50:Sn",
        "51:Sb", "52:Te", "53:I", "54:Xe", "55:Cs", "56:Ba", "57:La", "58:Ce", "59:Pr", "60:Nd",
        "61:Pm", "62:Sm", "63:Eu", "64:Gd", "65:Tb", "66:Dy", "67:Ho", "68:Er", "69:Tm", "70:Yb",
        "71:Lu", "72:Hf", "73:Ta", "74:W", "75:Re", "76:Os", "77:Ir", "78:Pt", "79:Au", "80:Hg",
        "81:Tl", "82:Pb", "83:Bi", "84:Po", "85:At", "86:Rn", "87:Fr", "88:Ra", "89:Ac", "90:Th",
        "91:Pa", "92:U", "93:Np", "94:Pu", "95:Am", "96:Cm", "97:Bk", "98:Cf", "99:Es", "100:Fm",
        "101:Md", "102:No", "103:Lr", "104:Rf", "105:Db", "106:Sg", "107:Bh", "108:Hs", "109:Mt",
        "110:Ds", "111:Rg", "112:Cn", "113:Nh", "114:Fl", "115:Mc", "116:Lv", "117:Ts", "118:Og"};

    printf("\n%42c |--------------------------|\n", ' ');
    printf("%42c |Periodic Table of Elements|\n", ' ');
    printf("%42c |--------------------------|\n\n", ' ');

    int i=0, spaces=1;
    while (i<118){
        if ( (n1!=0 && n2!=0) && (n4!=0 && n5!=0) && (!(strcmp(n3,"0")==0)) ){
            if ((AtomicNumber[i+1]>=n1 && AtomicNumber[i+1]<=n2)&&(AtomicMass[i]>=n4 && AtomicMass[i]<=n5)&&(strcmp(n3,ChemicalGroup[i])==0)){
                printf("\033[31m%7s\033[0m",table[i]);  
            } else {
                printf("%7s",table[i]);
            }
        } else if ((n1!=0 && n2!=0) && (n4!=0 && n5!=0)){
            if ((AtomicNumber[i+1]>=n1 && AtomicNumber[i+1]<=n2)&&(AtomicMass[i]>=n4 && AtomicMass[i]<=n5)){
                printf("\033[31m%7s\033[0m",table[i]);  
            } else {
                printf("%7s",table[i]);
            }
        } else if ((n1!=0 && n2!=0) && (!(strcmp(n3,"0")==0))){
            if ((AtomicNumber[i+1]>=n1 && AtomicNumber[i+1]<=n2)&&(strcmp(n3,ChemicalGroup[i])==0)){
                printf("\033[31m%7s\033[0m",table[i]);  
            } else {
                printf("%7s",table[i]);
            }
        } else if ((n4!=0 && n5!=0) && (!(strcmp(n3,"0")==0))){
            if ((AtomicMass[i]>=n4 && AtomicMass[i]<=n5)&&(strcmp(n3,ChemicalGroup[i])==0)){
                printf("\033[31m%7s\033[0m",table[i]);  
            } else {
                printf("%7s",table[i]);
            }
        } else if (n1!=0 && n2!=0){
            if ((AtomicNumber[i+1]>=n1 && AtomicNumber[i+1]<=n2)){
                printf("\033[31m%7s\033[0m",table[i]);  
            } else {
                printf("%7s",table[i]);
            }
        } else if (n4!=0 && n5!=0){
            if ((AtomicMass[i]>=n4 && AtomicMass[i]<=n5)){
                printf("\033[31m%7s\033[0m",table[i]);  
            } else {
                printf("%7s",table[i]);
            }
        } else if ((strcmp(n3,"0")!=0)){
            if (strcmp(n3,ChemicalGroup[i])==0){
                printf("\033[31m%7s\033[0m",table[i]);  
            } else {
                printf("%7s",table[i]);
            }
        } else {
            printf("%7s",table[i]);
        }

        if (i==0){
            for (int y=0; y<16; y++){
                printf("%7c", ' ');
                ++spaces;
            }
        }
        if (i==3 || i==11){
            for (int y=0; y<10; y++){
                printf("%7c", ' ');
                ++spaces;
            }
        }

        if(i==55 || i==87){
            i=i+15;
            printf("%7c", ' ');
            ++spaces;
        }
        if (i==117){
            printf("\n");
            for (int y=0; y<3; y++){
                printf("%7c", ' ');
                ++spaces;
            }
           i=i-62;
        }
        if (i==70 && spaces>=126){
            printf("\n");
            for (int y=0; y<3; y++){
                printf("%7c", ' ');
                ++spaces;
            }
            i=i+17;
        }
        if (i==102 && spaces>=144){
            i=i+15;
        }

        if (spaces%18==0){
            printf("\n");
        }
        ++i;
        ++spaces;
    }   
}

int binary_search(int array[], int size, int n){
    int left=0, right=size-1, mid;
    while (left<=right){
        mid=(right+left)/2;
        if (array[mid]==n){
            return mid;
        } 
        if (array[mid]<n){
            left=mid+1;
        } else{
            right=mid-1;
        }
    }

    return -1;
}

int linear_search(char array[][20], int size, char n[]){
    for (int i=0; i<size; i++){
        if (strcmp(array[i], n) == 0) {
            return i;
        }
    }
    return -1;

}

int input(int a, int b){
    int n;
    do{
        if(scanf("%d", &n)!=1 || (n<a || n>b)){
            printf(" Invalid input! Try again.\n");
            while (getchar()!='\n');
            printf(" Type your selection (1, 2 or 3): ");
        } else {
            break;
        }
    } while (1);

    return n;
}