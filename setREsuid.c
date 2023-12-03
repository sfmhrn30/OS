#include <stdio.h>
#include <unistd.h>

int main()
{
    uid_t uid;
    printf("Before setting the uid and gid\nreal user id: %d\nreal grp id: %d\neffective user id: %d\neffective grp id: %d\n", getuid(), getgid(), geteuid(), getegid());
    setresuid(1001, 1001, 1001);
    setresgid(1002, 1002, 1002);
    printf("After using resuid and resgid\nreal user id: %d\nreal grp id: %d\neffective user id: %d\neffective grp id: %d\n", getuid(), getgid(), geteuid(), getegid());
    setfsuid(1001);
    setfsgid(1002);

    printf("After using fsuid and fsgid\nreal user id: %d\nreal grp id: %d\neffective user id: %d\neffective grp id: %d\n", getuid(), getgid(), geteuid(), getegid());
    return 0;
}
