#include<iostream>
#include<stdlib.h>
#include<random>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;

//functie pentru afisarea unui array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

///INCEPE BUBBLE SORT
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Ultimele i elemente sunt deja sortate
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}

///SE TERMINA BUBBLE SORT

///INCEPE COUNTING SORT
void CountingSort(int arr[], int sz) {
	int i, j, k;
	int idx = 0;
	int min, max;

	min = max = arr[0];
	for(i = 1; i < sz; i++) {
		min = (arr[i] < min) ? arr[i] : min;
		max = (arr[i] > max) ? arr[i] : max;
	}

	k = max - min + 1;
	// creaza k bucketuri
	int *B = new int [k];
	for(i = 0; i < k; i++) B[i] = 0;

	for(i = 0; i < sz; i++) B[arr[i] - min]++;
	for(i = min; i <= max; i++)
		for(j = 0; j < B[i - min]; j++) arr[idx++] = i;

	delete [] B;
}
///SE TERMINA COUNTING SORT

///INCEPE RADIX SORT LSD
void RadixSortLSD(int *a, int arraySize)
{
	int i, bucket[arraySize], maxVal = 0, digitPosition =1 ;
	for(i = 0; i < arraySize; i++) {
		if(a[i] > maxVal) maxVal = a[i];
	}

	/* maxVal: decide countul lui while
	           daca maxVal are 3 cifre, atunci trecem prin while de 3 ori */
	while(maxVal/digitPosition > 0) {
		// resetam counterul
		int digitCount[10] = {0};

		// numaram pos cifre (keys)
		for(i = 0; i < arraySize; i++)
			digitCount[a[i]/digitPosition%10]++;

		// countul acumulat
		for(i = 1; i < 10; i++)
			digitCount[i] += digitCount[i-1];

		// Pentru a pastra ordinea, incepem de la coada
		for(i = arraySize - 1; i >= 0; i--)
			bucket[--digitCount[a[i]/digitPosition%10]] = a[i];

		// rearanjam arrayul original folosind elementele din bucketuri
		for(i = 0; i < arraySize; i++)
			a[i] = bucket[i];

		// aici, arrayul e sortat dupa a digitPosition cifra

		// mutat positia cifrei cu unu, spre stanga
		digitPosition *= 10;
	}
 }
///SE TERMINA RADIX SORT LSD

///INCEPE MERGE SORT
// imbina doua subarrayuri alle lui arr[].
// primul subarray este arr[l..m]
// al doilea subarray este arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // cream arrayuri temporare
    int L[n1], R[n2];

    // copiem data in arrayurile temporare L[] si R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // imbinam arrayurile temporare inapoi in arr[l..r]

    // indexul initial al primului subarray
    int i = 0;

    // indexul initial al celui de-al doilea subarray
    int j = 0;

    // indexul initial al arraylui obtinut in urma imbinarii
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copiem elementele ramasse din
    // L[], daca exista
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copiem elementele ramasse din
    // R[], daca exista
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l este pentru indexul din stanga si r este
// pentru indexul din dreapta al subarrayului
// lui arr ce trebuie sortat
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returneaza recursiv
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
///SE TERMINA MERGE SORT

///INCEPE QUICK SORT
    /* aceasta functie ia ultimul element drept pivot, pune
    elementul pivot in pozitia sa corecta in arrayul
    sortat si le pune pe toate cele mai mioi (decat pivotul)
    la stanga pivotului si pe toate cele mai mari la dreapta
    pivotului */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // indexul elementului mai mic

    for (int j = low; j <= high- 1; j++)
    {
        /* daca elementul curent este mai mic decat sau
        egal cu pivotul */
        if (arr[j] <= pivot)
        {
            i++;    // incrementam indexul elementului mai mic
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

    /* functia principala care implementeaza QuickSort
    arr[] --> arrayul ce trebuie sortat,
    low  --> indexul de inceput,
    high  --> indexul de final */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi este indexul de partitionare, arr[p] este acum
           la locul potrivit */
        int pi = partition(arr, low, high);

        /* sortam separat elementele dinaintea
        partitiei si dupa ea*/
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
///SE TERMINA QUICK SORT

void menu_output(){
    cout<<"\n Niculae Tiberiu-Constantin Grupa 134 - Tema 1 - Sortari: \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Bubble Sort"; cout<<"\n";
    cout<<"2. Counting Sort"; cout<<"\n";
    cout<<"3. Radix Sort(LSD)"; cout<<"\n";
    cout<<"4. Merge Sort"; cout<<"\n";
    cout<<"5. Quick Sort"; cout<<"\n";
    cout<<"6. Bubble Sort(vector aproape sortat)"; cout<<"\n";
    cout<<"7. Counting Sort(vector aproape sortat)"; cout<<"\n";
    cout<<"8. Radix Sort(LSD)(vector aproape sortat)"; cout<<"\n";
    cout<<"9. Merge Sort(vector aproape sortat)"; cout<<"\n";
    cout<<"10. Quick Sort(vector aproape sortat)"; cout<<"\n";
    cout<<"11. Bubble Sort(vector constant)"; cout<<"\n";
    cout<<"12. Counting Sort(vector constant)"; cout<<"\n";
    cout<<"13. Radix Sort(LSD)(vector constant)"; cout<<"\n";
    cout<<"14. Merge Sort(vector constant)"; cout<<"\n";
    cout<<"15. Quick Sort(vector constant)"; cout<<"\n";
    cout<<"0. Iesire."; cout<<"\n";
}
void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;

    do
    {
        menu_output();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;

        if (option==1)
        {
            ///cod corespunzator pentru optiunea 1
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>500000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = dis(gen);
                    arr2[j] = arr[j];
                }
                cout<<"Vectorul a fost generat!"<<endl;
                auto start = high_resolution_clock::now();
                bubbleSort(arr, N);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==2)
        {
            ///----||---- 2
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>250000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = dis(gen);
                    arr2[j] = arr[j];
                }
                cout<<"Vectorul a fost generat!"<<endl;
                auto start = high_resolution_clock::now();
                CountingSort(arr, N);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==3)
        {
            ///----||---- 3
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>150000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = dis(gen);
                    arr2[j] = arr[j];
                }
                cout<<"Vectorul a fost generat!"<<endl;
                auto start = high_resolution_clock::now();
                RadixSortLSD(arr, N);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==4)
        {
            ///----||---- 4
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>150000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = dis(gen);
                    arr2[j] = arr[j];
                }
                cout<<"Vectorul a fost generat!"<<endl;
                auto start = high_resolution_clock::now();
                mergeSort(arr, 0, N-1);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==5)
        {
            ///----||---- 5
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>250000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = dis(gen);
                    arr2[j] = arr[j];
                }
                cout<<"Vectorul a fost generat!"<<endl;
                auto start = high_resolution_clock::now();
                quickSort(arr, 0, N-1);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==6)
        {
            ///----||---- 6
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>250000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = dis(gen);
                    arr2[j] = arr[j];
                }
                cout<<"Vectorul a fost generat!"<<endl;
                quickSort(arr, 0, N-2);
                cout<<"Vectorul a fost aproape sortat!"<<endl;
                auto start = high_resolution_clock::now();
                bubbleSort(arr, N);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==7)
        {
            ///----||---- 7
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>250000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = dis(gen);
                    arr2[j] = arr[j];
                }
                cout<<"Vectorul a fost generat!"<<endl;
                quickSort(arr, 0, N-2);
                cout<<"Vectorul a fost aproape sortat!"<<endl;
                auto start = high_resolution_clock::now();
                CountingSort(arr, N);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==8)
        {
            ///----||---- 8
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>150000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = dis(gen);
                    arr2[j] = arr[j];
                }
                cout<<"Vectorul a fost generat!"<<endl;
                quickSort(arr, 0, N-2);
                cout<<"Vectorul a fost aproape sortat!"<<endl;
                auto start = high_resolution_clock::now();
                RadixSortLSD(arr, N);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==9)
        {
            ///----||---- 9
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>150000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = dis(gen);
                    arr2[j] = arr[j];
                }
                cout<<"Vectorul a fost generat!"<<endl;
                quickSort(arr, 0, N-2);
                cout<<"Vectorul a fost aproape sortat!"<<endl;
                auto start = high_resolution_clock::now();
                mergeSort(arr, 0, N-1);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==10)
        {
            ///----||---- 10
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>25000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = dis(gen);
                    arr2[j] = arr[j];
                }
                cout<<"Vectorul a fost generat!"<<endl;
                quickSort(arr, 0, N-2);
                cout<<"Vectorul a fost aproape sortat!"<<endl;
                auto start = high_resolution_clock::now();
                quickSort(arr, 0, N-1);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==11)
        {
            ///----||---- 11
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>250000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                int aux = dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = aux;
                    arr2[j] = aux;
                }
                cout<<"Vectorul constant a fost generat!"<<endl;
                auto start = high_resolution_clock::now();
                bubbleSort(arr, N);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==12)
        {
            ///----||---- 12
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>250000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                int aux = dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = aux;
                    arr2[j] = aux;
                }
                cout<<"Vectorul constant a fost generat!"<<endl;
                auto start = high_resolution_clock::now();
                CountingSort(arr, N);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==13)
        {
            ///----||---- 13
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>150000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                int aux = dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = aux;
                    arr2[j] = aux;
                }
                cout<<"Vectorul constant a fost generat!"<<endl;
                auto start = high_resolution_clock::now();
                RadixSortLSD(arr, N);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==14)
        {
            ///----||---- 14
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>150000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                int aux = dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = aux;
                    arr2[j] = aux;
                }
                cout<<"Vectorul constant a fost generat!"<<endl;
                auto start = high_resolution_clock::now();
                mergeSort(arr, 0, N-1);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==15)
        {
            ///----||---- 15
            int T, N, Max;
            cout<<"Introduceti numarul de teste: ";
            cin>>T;
            for(int i=0; i<T; i++)
            {
                cout<<"N = ";
                cin>>N;
                if(N>25000)
                {
                    cout<<"EROARE!"<<endl<<"Introduceti o valoare mai mica la urmatoarea rulare!";
                    break;
                }
                cout<<"Max = ";
                cin>>Max;
                int arr[N], arr2[N];
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, Max);
                dis(gen);
                int aux = dis(gen);
                for(int j=0; j<N; j++)
                {
                    arr[j] = aux;
                    arr2[j] = aux;
                }
                cout<<"Vectorul constant a fost generat!"<<endl;
                auto start = high_resolution_clock::now();
                quickSort(arr, 0, N-1);
                auto stop = high_resolution_clock::now();
                cout<<"Vectorul a fost sortat!"<<endl;
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << endl;
                auto start2 = high_resolution_clock::now();
                sort(arr2, arr2+N);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                cout << duration2.count() << endl;
            }
        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>15)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}

// Driver code
int main()
{
    menu();
    return 0;
}
