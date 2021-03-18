#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void ft_putchar(char c);
int ft_putstr(char *s);
int _ft_strlen(char *s);
int _ft_strcmp(char *str1, char *str2);
char *_ft_strcpy(char *dest, char *src);
int _ft_write(int fd, char *str, size_t count);
int _ft_read(int fd, char *buf, size_t count);
char *_ft_strdup(char *str);

int main()
{	
	char *str = "12345678";
	int ret;
	printf("---ft_strlen---\n");
	ret = _ft_strlen(str);
	printf("%d\n", ret);
	ret = strlen(str);
	printf("%d\n", ret);



	printf("\n---ft_strcpy---\n");
	char dest1[20] = "";
	char dest2[20] = "";
	char *res;
	char src[7] = "abcdef";
	res = _ft_strcpy(dest1, src);
	printf("%s\n", res);
	res = strcpy(dest2, src);
	printf("%s\n", res);



	printf("\n---ft_strcmp---\n");
	char *str1 = "argh"; 
	char *str2 = "argh";
	ret = _ft_strcmp(str1, str2);
	printf("%d\n", ret);
	ret = strcmp(str1, str2);
	printf("%d\n", ret);
	ret = _ft_strcmp("abcdefg", "abcdefgh");
	printf("%d\n", ret);
	ret = strcmp("abcdefg", "abcdefgh");
	printf("%d\n", ret);




	printf("\n---ft_write---\n");
	ret = _ft_write(1, "abcdef", 6);
	printf("  %d\n", ret);
	printf("errno = %s\n", strerror(errno));
	ret = write(1, "abcdef", 6);
	printf("  %d\n", ret);
	printf("errno = %s\n", strerror(errno));
	ret = _ft_write(-1, "abcdef", 10);
	printf("ret = %d | errno = %s\n", ret, strerror(errno));
	ret = write(-1, "abcdef", 10);
	printf("ret = %d | errno = %s\n", ret, strerror(errno));



	printf("\n---ft_read---\n");
	char buf[20];
	int fd;
	char *filename = "text.txt";
	fd = open(filename, O_RDONLY);
	ret = _ft_read(fd, buf, 10);
	buf[ret] = 0;
	printf("%s - %d\n", buf, ret);
	close(fd);
	fd = open(filename, O_RDONLY);
	ret = read(fd, buf, 10);
	buf[ret] = 0;
	printf("%s - %d\n", buf, ret);
	ret = _ft_read(-1, buf, 10);
	printf("ret = %d | errno = %s\n", ret, strerror(errno));
	ret = read(-1, buf, 10);
	printf("ret = %d | errno = %s\n", ret, strerror(errno));
	ret = _ft_read(fd, buf, -10);
	printf("ret = %d | errno = %s\n", ret, strerror(errno));
	ret = read(fd, buf, -10);
	printf("ret = %d | errno = %s\n", ret, strerror(errno));


	printf("\n---ft_strdup---\n");
	char *newstr;
	newstr = _ft_strdup("haha!haha!");
	printf("%s\n", newstr);
	newstr = strdup("haha!haha!");
	printf("%s\n", newstr);
	return (0);
}
