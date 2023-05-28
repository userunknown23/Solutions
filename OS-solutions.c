// ---------------------------------------------------------------------
// 1 i) PROGRAM USING SYSTEM CALL fork()
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    pid = fork();
    
    if (pid < 0) {
        printf("fork failed\n");
        exit(1);
    } else if (pid == 0) {
        execlp("whoami", "whoami", NULL);
        exit(0);
    } else {
        printf("\nProcess id is %d\n", getpid());
        wait(NULL);
        exit(0);
    }
}
//ii) PROGRAM USING SYSTEM CALLS getpid() & getppid()
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main( ) {
    int pid;
    pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(0);
    }
    if (pid == 0) {
        printf("\nChild process is under execution");
        printf("\nProcess id of the child process is %d", getpid());
        printf("\nProcess id of the parent process is %d", getppid());
    } else {
        printf("\nParent process is under execution");
        printf("\nProcess id of the parent process is %d", getpid());
        printf("\nProcess id of the child process in parent is %d", pid);
        printf("\nProcess id of the parent of parent is %d", getppid());
    }

    return 0;
}
//iii)PROGRAM USING SYSTEM CALLS opendir( ) readdir( ) closedir()
#include <stdio.h>
#include <sys/types.h> 
#include <sys/dir.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *rddir;
    printf("\nListing the directory content\n");
    dir = opendir(argv[1]);

    if (dir == NULL) {
        perror("opendir failed");
        return 1;
    }

    while ((rddir = readdir(dir)) != NULL) {
        printf("%s\t\n", rddir->d_name);
    }

    closedir(dir);
    return 0;
}
//iv) PROGRAM USING SYSTEM CALL exec( )
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("\n exec system call");
    printf("displaying the date");
    execlp("/bin/date", "date", NULL);
    return 0;
}
//v) PROGRAM USING SYSTEM CALLS open( ), read() & write()
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {
    int fd[2];
    char buf1[25] = "just a test\n";
    char buf2[50];
    fd[0] = open("file1", O_RDWR);
    fd[1] = open("file2", O_RDWR);
    write(fd[0], buf1, strlen(buf1));
    printf("\nEnter the text now….\n");
    fgets(buf1, sizeof(buf1), stdin);
    write(fd[0], buf1, strlen(buf1));
    lseek(fd[0], 0, SEEK_SET);
    read(fd[0], buf2, sizeof(buf1));
    write(fd[1], buf2, sizeof(buf2));
    close(fd[0]);
    close(fd[1]);
    printf("\n");
    return 0;
}
// --------------------------------------------------------------
// --------------------------------------------------------------
//3
#include<stdio.h>
// #include<conio.h>
struct process
{
int pid; int bt; int wt; int tt;
int prior;
}
p[10],temp;
int main()
{
int i,j,n,totwt,tottt,arg1,arg2;
// clrscr();
printf("enter the number of process :");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
p[i].pid=i;
printf("enter the burst time :");
scanf("%d",&p[i].bt);
printf("\n enter the priority :");
scanf("%d",&p[i].prior);
}
for(i=1;i<n;i++)
{
for(j=i+1;j<=n;j++)
{
if(p[i].prior>p[j].prior)
{
temp.pid=p[i].pid;
p[i].pid=p[j].pid; p[j].pid=temp.pid; temp.bt=p[i].bt; p[i].bt=p[j].bt; p[j].bt=temp.bt;
temp.prior=p[i].prior;
p[i].prior=p[j].prior;
p[j].prior=temp.prior;
}
}
} p[i].wt=0; p[1].tt=p[1].bt+p[1].wt;
i=2; while(i<=n)
{
p[i].wt=p[i-1].bt+p[i-1]
.wt;
p[i].tt=p[i].bt+p[i].wt;
i++;
}
i=1;
totwt=tottt=0;
printf("\n process to \t bt \t wt \t tt"); 
while(i<=n)
{
printf("\n%d\t %d\t %d\t %d\t",p[i].pid,p[i].bt,p[i].wt,p[i].tt); totwt=p[i].wt+totwt;
tottt=p[i].tt+tottt;
i++;
}
arg1=totwt/n;
arg2=tottt/n;
printf("\n arg1=%d \t arg2=%d\t",arg1,arg2); 
// getch();
return 0;
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//4
#include<stdio.h>
// #include<conio.h>
struct process
{
int pid;
int bt; int wt; int tt;
}p[10],temp;
int main()
{
int i,j,n,totwt,tottt; float avg1,avg2; 
// clrscr();
printf("\nEnter the number of process:\t");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
p[i].pid=i;
printf("\nEnter the burst time:\t");
scanf("%d",&p[i].bt);
}
for(i=1;i<n;i++){
for(j=i+1;j<=n;j++)
{
if(p[i].bt>p[j].bt)
{
temp.pid=p[i].pid;
p[i].pid=p[j].pid;
p[j].pid=temp.pid;
temp.bt=p[i].bt;p[i].bt=p[j].bt;
p[j].bt=temp.bt;
}}}
p[1].wt=0; p[1].tt=p[1].bt+p[1].wt; i=2;
while(i<=n){
p[i].wt=p[i-1].bt+p[i-1].wt;
p[i].tt=p[i].bt+p[i].wt;
i++;
}
i=1;
totwt=tottt=0;
printf("\nProcess id \tbt \twt \ttt");
while(i<=n){
printf("\n\t%d \t%d \t%d t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt); totwt=p[i].wt+totwt;
tottt=p[i].tt+tottt; i++;
}
avg1=totwt/n;
avg2=tottt/
n;
printf("\nAVG1=%f\t AVG2=%f",avg1,avg2); 
// getch();
return 0; 
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//5
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Function to perform matrix addition
void matrixAddition(int rows, int cols, int matrix1[][MAX_COLS], int matrix2[][MAX_COLS], int result[][MAX_COLS]) {
    int i, j;

    // Add corresponding elements of both matrices
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    int rows, cols;
    int i, j;
    int shmid;
    key_t key;
    int (*matrix1)[MAX_COLS];
    int (*matrix2)[MAX_COLS];
    int (*result)[MAX_COLS];

    // Prompt the user for the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Create shared memory segment for matrix 1
    key = ftok(".", 'A');
    shmid = shmget(key, sizeof(int[MAX_ROWS][MAX_COLS]), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment for matrix 1
    matrix1 = shmat(shmid, 0, 0);
    if (matrix1 == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Create shared memory segment for matrix 2
    key = ftok(".", 'B');
    shmid = shmget(key, sizeof(int[MAX_ROWS][MAX_COLS]), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment for matrix 2
    matrix2 = shmat(shmid, 0, 0);
    if (matrix2 == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Create shared memory segment for result matrix
    key = ftok(".", 'C');
    shmid = shmget(key, sizeof(int[MAX_ROWS][MAX_COLS]), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment for result matrix
    result = shmat(shmid, 0, 0);
    if (result == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Prompt the user to enter matrix 1 elements
    printf("Enter the elements of matrix 1:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Prompt the user to enter matrix 2 elements
    printf("Enter the elements of matrix 2:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
}
}
  // Fork a child process
pid_t pid = fork();

if (pid == -1) {
    perror("fork");
    exit(1);
} else if (pid == 0) {
    // Child process performs matrix addition

    // Perform matrix addition
    matrixAddition(rows, cols, matrix1, matrix2, result);

    // Detach shared memory segments
    shmdt(matrix1);
    shmdt(matrix2);
    shmdt(result);

    printf("Matrix addition completed in child process.\n");
    exit(0);
} else {
    // Parent process waits for the child to complete

    // Wait for the child process to complete
    wait(NULL);

    printf("Matrix addition completed in parent process.\n");

    // Print the result matrix
    printf("Resultant Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Detach and remove shared memory segments
    shmdt(matrix1);
    shmdt(matrix2);
    shmdt(result);
    shmctl(shmid, IPC_RMID, NULL);
}

return 0;
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//6

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define MAX_ODD_NUMBERS 11

// Function to generate odd numbers and store them in shared memory
void generateOddNumbers(int *numbers) {
    int i;
    int num = 1;

    // Generate odd numbers and store them in shared memory
    for (i = 0; i < MAX_ODD_NUMBERS; i++) {
        numbers[i] = num;
        num += 2;
    }
}

int main() {
    int shmid;
    key_t key;
    int *numbers;
    int i;

    // Create shared memory segment
    key = ftok(".", 'A');
    shmid = shmget(key, MAX_ODD_NUMBERS * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    numbers = (int *)shmat(shmid, 0, 0);
    if (numbers == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Generate odd numbers and store them in shared memory
    generateOddNumbers(numbers);

    // Print the odd numbers
    printf("Odd Numbers generated using shared memory:\n");
    for (i = 0; i < MAX_ODD_NUMBERS; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Detach and remove shared memory segment
    shmdt(numbers);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//7

#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

// Function to sort an array in ascending order
void sortArray(int arr[], int n) {
    int i, j;
    int temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform C-SCAN disk scheduling
void cScanDiskScheduling(int requests[], int n, int head_position, int disk_size) {
    int total_seek_time = 0;
    int direction = 1; // 1 for moving towards higher track numbers, -1 for moving towards lower track numbers

    // Sort the requests in ascending order
    sortArray(requests, n);

    // Find the index where head position is located in the sorted array
    int i;
    for (i = 0; i < n; i++) {
        if (requests[i] >= head_position) {
            break;
        }
    }

    // Move towards higher track numbers until reaching the end
    printf("Sequence of disk access: %d", head_position);
    for (; i < n; i++) {
        printf(" -> %d", requests[i]);
        total_seek_time += abs(requests[i] - head_position);
        head_position = requests[i];
    }

    // Move to track 0
    printf(" -> %d", 0);
    total_seek_time += head_position;

    // Move towards higher track numbers again until reaching the end of disk size
    printf(" -> %d", disk_size - 1);
    total_seek_time += disk_size - 1;

    // Move back to the initial head position
    printf(" -> %d", head_position);
    total_seek_time += disk_size - 1 - head_position;

    printf("\nTotal Seek Time: %d\n", total_seek_time);
}

int main() {
    int n, head_position, disk_size;
    int requests[MAX_REQUESTS];
    int i;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head_position);

    printf("Enter the disk size: ");
    scanf("%d", &disk_size);

    cScanDiskScheduling(requests, n, head_position, disk_size);

    return 0;
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//9
#include<stdio.h>
struct process
{
int pid;
int bt;
int wt,tt;
}p[10];
int main()
{
int i,n,totwt,tottt,avg1,avg2; 
// clrscr();
printf("enter the no of process :\n"); scanf("%d",&n);
for(i=1;i<=n;i++)
{
p[i].pid=i;
printf("enter the burst time  n :"); scanf("%d",&p[i].bt);
} p[1].wt=0;
p[1].tt=p[1].bt+p[1].wt;
i=2; while(i<=n)
{
p[i].wt=p[i-1].bt+p[i-1].wt;
p[i].tt=p[i].bt+p[i].wt; i ++;
} i=1; totwt=tottt=0;
printf("\n processid \t bt\t wt\t tt\n");
while(i<=n){ 
    printf("\n\t %d \t%d \t%d \t%d",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
totwt=p[i].wt+totwt; tottt=p[i].tt+tottt; i++;}
avg1=totwt/n; avg2=tottt/n; printf("\navg1=%d \t avg2=%d\t",avg1,avg2);
// getch();
return 0;
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//10

#include <stdio.h>
int main()
{
    int pt[10][10], a[10][10], at[10], pname[10][10], i, j, n, k = 0, q, sum = 0;
    float avg;
    printf("\n\nEnter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            pt[i][j] = 0;
            a[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("\n\nEnter the process time for process %d: ", i + 1);
        scanf("%d", &pt[i][0]);
    }
    printf("\n\nEnter the time slice: ");
    scanf("%d", &q);

    printf("\n\n");

    for (j = 0; j < 10; j++)
    {
        for (i = 0; i < n; i++)
        {
            a[2 * j][i] = k;
            if ((pt[i][j] <= q) && (pt[i][j] != 0))
            {
                pt[i][j + 1] = 0;
                printf(" %d P%d %d\n", k, i + 1, k + pt[i][j]);
                k += pt[i][j];
                a[2 * j + 1][i] = k;
            }
            else if (pt[i][j] != 0)
            {
                pt[i][j + 1] = pt[i][j] - q;
                printf(" %d P%d %d\n", k, i + 1, (k + q));
                k += q;
                a[2 * j + 1][i] = k;
            }
            else
            {
                a[2 * j][i] = 0;
                a[2 * j + 1][i] = 0;
            }
        }
    }
    for (i = 0; i < n; i++)
        sum += a[0][i];

    for (i = 0; i < n; i++)
    {
        for (j = 1; j < 10; j++)
        {
            if ((a[j][i] != 0) && (a[j + 1][i] != 0) && ((j + 1) % 2 == 0))
                sum += (a[j + 1][i] - a[j][i]);
        }
    }
    avg = (float)sum / n;
    printf("\n\nAverage waiting time = %f msec", avg);
    sum = avg = 0;
    for (j = 0; j < n; j++)
    {
        i = 1;
        while (a[i][j] != 0)
            i += 1;
        sum += a[i - 1][j];
    }
    avg = (float)sum / n;
    printf("\n\nAverage turnaround time = %f msec\n\n", avg);
    return 0;
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//11

#include<stdio.h>
int main()
{
    int buffer[10], bufsize, in, out, produce, consume, choice = 0;
    in = 0;
    out = 0;
    bufsize = 10;
    while (choice != 3)
    {
        printf("\n1. Produce \t 2. Consume \t3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                if ((in + 1) % bufsize == out)
                    printf("\nBuffer is Full");
                else
                {
                    printf("\nEnter the value: ");
                    scanf("%d", &produce);
                    buffer[in] = produce;
                    in = (in + 1) % bufsize;
                }
                break;
            case 2:
                if (in == out)
                    printf("\nBuffer is Empty");
                else
                {
                    consume = buffer[out];
                    printf("\nThe consumed value is %d", consume);
                    out = (out + 1) % bufsize;
                }
                break;
        }
    }
    return 0;
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//12 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];
    char message[] = "Hello, child process!";

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        close(pipefd[1]); // Close the write end of the pipe

        // Read the message from the parent process
        if (read(pipefd[0], buffer, BUFFER_SIZE) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Child process received message: %s\n", buffer);

        close(pipefd[0]); // Close the read end of the pipe
    } else {
        // Parent process
        close(pipefd[0]); // Close the read end of the pipe

        // Write the message to the child process
        if (write(pipefd[1], message, strlen(message) + 1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(pipefd[1]); // Close the write end of the pipe
    }

    return 0;
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//13 

#include<stdio.h>

int main() {
    int k = 0, output[10], d = 0, t = 0, ins[5], i, avail[5], allocated[10][5], need[10][5], MAX[10][5], pno, P[10], j, rz, count = 0;

    printf("\n Enter the number of resources: ");
    scanf("%d", &rz);

    printf("\n Enter the max instances of each resource\n");
    for (i = 0; i < rz; i++) {
        avail[i] = 0;
        printf("%c = ", (i + 97));
        scanf("%d", &ins[i]);
    }

    printf("\n Enter the number of processes: ");
    scanf("%d", &pno);

    printf("\n Enter the allocation matrix\n");
    for (i = 0; i < rz; i++)
        printf(" %c", (i + 97));
    printf("\n");

    for (i = 0; i < pno; i++) {
        P[i] = i;
        printf("P[%d] ", P[i]);
        for (j = 0; j < rz; j++) {
            scanf("%d", &allocated[i][j]);
            avail[j] += allocated[i][j];
        }
    }

    printf("\n Enter the MAX matrix\n");
    for (i = 0; i < rz; i++) {
        printf(" %c", (i + 97));
        avail[i] = ins[i] - avail[i];
    }

    printf("\n");
    for (i = 0; i < pno; i++) {
        printf("P[%d] ", i);
        for (j = 0; j < rz; j++)
            scanf("%d", &MAX[i][j]);
    }

    printf("\n");

    A:
    d = -1;
    for (i = 0; i < pno; i++) {
        count = 0;
        t = P[i];
        for (j = 0; j < rz; j++) {
            need[t][j] = MAX[t][j] - allocated[t][j];
            if (need[t][j] <= avail[j])
                count++;
        }
        if (count == rz) {
            output[k++] = P[i];
            for (j = 0; j < rz; j++)
                avail[j] += allocated[t][j];
        } else
            P[++d] = P[i];
    }

    if (d != -1) {
        pno = d + 1;
        goto A;
    }

    printf("\t <");
    for (i = 0; i < k; i++)
        printf(" P[%d] ", output[i]);
    printf(">\n");

    return 0;
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//14

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[2];

void* doSomeThing(void* arg)
{
    unsigned long i = 0;
    pthread_t id = pthread_self();
    
    if (pthread_equal(id, tid[0]))
    {
        printf("\nFirst thread processing\n");
    }
    else
    {
        printf("\nSecond thread processing\n");
    }
    
    for (i = 0; i < (0xFFFFFFFF); i++);
    
    return NULL;
}

int main(void)
{
    int i = 0;
    int err;
    
    while (i < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        
        if (err != 0)
        {
            printf("\nCan't create thread: [%s]", strerror(err));
        }
        else
        {
            printf("\nThread created successfully\n");
        }
        
        i++;
    }
    
    sleep(5);
    
    return 0;
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//15 

#include <iostream>
using namespace std;

#define max 25

int main()
{
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    static int bf[max], ff[max];

    cout << "\n\tMemory Management Scheme - First Fit" << endl;
    cout << "Enter the number of blocks: ";
    cin >> nb;
    cout << "Enter the number of files: ";
    cin >> nf;

    cout << "\nEnter the size of the blocks:" << endl;
    for (i = 1; i <= nb; i++)
    {
        cout << "Block " << i << ": ";
        cin >> b[i];
    }

    cout << "Enter the size of the files:" << endl;
    for (i = 1; i <= nf; i++)
    {
        cout << "File " << i << ": ";
        cin >> f[i];
    }

    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                {
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }

    cout << "\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragmentation" << endl;
    for (i = 1; i <= nf; i++)
        cout << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i] << endl;
  
    return 0;
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//16


#include<stdio.h>

#define max 25

int main()
{
    int frag[max], b[max], f[max], i, j, nb, nf, temp, lowest = 10000;
    static int bf[max], ff[max];

    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for (i = 1; i <= nf; i++)
    {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    for (i = 1; i <= nf; i++)
    {
        lowest = 10000;
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0 && lowest > temp)
                {
                    ff[i] = j;
                    lowest = temp;
                }
            }
        }
        frag[i] = lowest;
        bf[ff[i]] = 1;
    }

    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment\n");
    for (i = 1; i <= nf && ff[i] != 0; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);

    return 0;
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//17

#include <iostream>
using namespace std;

#define max 25

int main()
{
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    static int bf[max], ff[max];

    cout << "\n\tMemory Management Scheme - First Fit" << endl;
    cout << "Enter the number of blocks: ";
    cin >> nb;
    cout << "Enter the number of files: ";
    cin >> nf;

    cout << "\nEnter the size of the blocks:" << endl;
    for (i = 1; i <= nb; i++)
    {
        cout << "Block " << i << ": ";
        cin >> b[i];
    }

    cout << "Enter the size of the files:" << endl;
    for (i = 1; i <= nf; i++)
    {
        cout << "File " << i << ": ";
        cin >> f[i];
    }

    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                {
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }

    cout << "\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragmentation" << endl;
    for (i = 1; i <= nf; i++)
        cout << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i] << endl;

    return 0;
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//18

#include<stdio.h>
// #include<conio.h>
int i,j,nof,nor,flag=0,ref[50],frm[50],pf=0,victim=-1;
void main()
{
// clrscr();
printf("\n \t\t\t FIFI PAGE REPLACEMENT ALGORITHM"); printf("\n Enter no.of frames. .. ");
scanf("%d",&nof);
printf("Enter number of Pages.\n");
scanf("%d",&nor);
printf("\n Enter the Page No.. "); for(i=0;i<nor;i++) scanf("%d",&ref[i]);
printf("\nThe given Pages are:"); for(i=0;i<nor;i++) printf("%4d",ref[i]); for(i=1;i<=nof;i++)
frm[i]=-1; printf("\n"); for(i=0;i<nor;i++)
{
flag=0;
printf("\n\t page no %d->\t",ref[i]);
for(j=0;j<nof;j++)
{
if(frm[j]==ref[i])
{
flag=1;
break;
}}
if(flag==0)
{
pf++; victim++; victim=victim%nof; frm[victim]=ref[i]; for(j=0;j<nof;j++) printf("%4d",frm[j]);
} }
printf("\n\n\t\t No.of pages faults...%d",pf);
// getch();
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//19

#include <iostream>
#include <vector>

struct File
{
    std::string name;
};

int main()
{
    int count;
    std::cout << "Enter the number of files: ";
    std::cin >> count;

    std::vector<File> files(count);

    for (int i = 0; i < count; i++)
    {
        std::cout << "Enter file name " << i + 1 << ": ";
        std::cin >> files[i].name;
    }

    std::cout << "root directory\n";
    std::cout << "|-- ";

    for (int i = 0; i < count; i++)
    {
        std::cout << files[i].name;
        if (i < count - 1)
            std::cout << "\n|\n|-- ";
    }

    return 0;
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
//20 

// 20.Linked List Allocation
#include<stdio.h>
// #include<conio.h>
struct file
{
char fname[10];
int start,size,block[10];
}f[10];
void main()
{
int i,j,n;
// clrscr();
printf("Enter no. of files:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter file name:");
scanf("%s",&f[i].fname);
printf("Enter starting block:");
scanf("%d",&f[i].start);
f[i].block[0]=f[i].start;
printf("Enter no.of blocks:");
scanf("%d",&f[i].size);
printf("Enter block numbers:");
for(j=1;j<=f[i].size;j++)
{
    scanf("%d",&f[i].block[j]);}}
    printf("File\tstart\tsize\tblock\n");
for(i=0;i<n;i++)
{
printf("%s\t%d\t%d\t",f[i].fname,f[i].start,f[i].size);
for(j=1;j<=f[i].size-1;j++)
printf("%d--->",f[i].block[j]);
printf("%d",f[i].block[j]);
printf("\n");
}
// getch();
}
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------