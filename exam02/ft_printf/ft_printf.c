#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

// 9. 진수 숫자 출력 함수
void ft_putnbr_base(long long num, int base)
{
	char *dec = "0123456789";
	char *hex = "0123456789abcdef";

	if (num < 0)
		num = -num;
	if (num >= base)
	{
		ft_putnbr_base(num / base, base);
		ft_putnbr_base(num % base, base);
	}
	else
	{
		if (base == 10)
			write(1, &dec[num], 1);
		else if (base == 16)
			write(1, &hex[num], 1);
	}
}


// 8-1. 숫자 길이 함수
int ft_numlen(int num)
{
	int i = 1;
	while (num /= 10)
		i++;
	return (i);
}

// 8-2. 16진수 숫자 길이 함수
int ft_hexlen(unsigned int num)
{
	int i = 1;
	while (num /= 16)
		i++;
	return (i);
}


// 7. n 길이만큼 문자열 출력
void ft_putnstr(char *s, int n)
{
	int i = 0;
	while (s[i] && i < n)
	{
		write(1, &s[i], 1);
		i++;
	}
}

// 6. 문자열 길이 구하는 함수
int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

// 5. with dot precision 처리하고 출력해주는 함수
// f: format
// conversion : s, d, x
// ap
int print_with_flags(char *f, char conversion, va_list ap)
{
	int width = 0;
	int dot = 0;
	int precision = 0;
	int nprinted = 0; // 이 함수의 리턴값으로 출력한 문자 갯수 의미
	int i = 0;

	// width, dot, precision 계산
	while (f[i])
	{
		// width
		if (('0' <= f[i] && f[i] <= '9') && !dot)
			width = (width * 10) + (f[i] - 48);
		// dot
		else if (f[i] == '.')
			dot = 1;
		else if (('0' <= f[i] && f[i] <= '9') && dot)
			precision = (precision * 10) + (f[i] - 48);
		i++;
	}

	char *str = 0;
	int num = 0;;
	unsigned int unum = 0;
	int len = 0;

	// s 처리
	if (conversion == 's')
	{
		if (!(str = va_arg(ap, char *)))
			str = "(null)";
		len = ft_strlen(str);
		if (dot)
		{
			if (len < precision) // precision이 문자열 길이보다 작으면
				precision = len;
		}
		else // . 이 없으면 pre = 0이기 때문에
			precision = len;
		i = 0;
		// width - precision 만큼 공백 출력
		while (i < width - precision)
		{
			write(1, " ", 1);
			nprinted++; // 공백 개수만큼 nprinted++
			i++;
		}
		nprinted += precision; // 출력할 문자 개수만큼 nprinted++
		ft_putnstr(str, precision); // precision 만큼 문자 출력
	}
	// d, x 처리
	else if (conversion == 'd' || conversion == 'x')
	{
		// d 라면
		if (conversion == 'd')
		{
			num = va_arg(ap, int);
			len = ft_numlen(num);
		}
		// x 라면
		else if (conversion == 'x')
		{
			unum = va_arg(ap, unsigned int); // unsigned int
			len = ft_hexlen(unum);
		}
		// 예외처리 0.0
		if (num == 0 && unum == 0 && dot && precision == 0)
		{
			i = 0;
			while (i < width)
			{
				write(1, " ", 1);
				nprinted++;
				i++;
			}
			return (nprinted);
		}
		// precision이 숫자 길이보다 작다면
		if (precision < len)
			precision = len;
		if (num < 0) // 음수라면 공백처리
			precision++;
		i = 0;
		// width - precision 만큼 공백 출력
		while (i < width - precision)
		{
			write(1, " ", 1);
			nprinted++;
			i++;
		}
		// 음수이면 '-' 출력
		if (num < 0)
		{
			write(1, "-", 1);
			len++;
		}
		i = 0;
		// precision - len(숫자 길이)만큼 0 출력
		while (i < precision - len)
		{
			write(1, "0", 1);
			i++;
		}
		nprinted += precision; // nprinted에 precision 만큼 더해준다.
		// 숫자 출력
		if (conversion == 'd')
			ft_putnbr_base(num, 10);
		else if (conversion == 'x')
			ft_putnbr_base(unum, 16);
	}
	free(f); // format을 free 해준다
	return (nprinted); // 출력한 글자 수 리턴
}

// 4. n 길이 만큼 새로운 문자열 할당 함수
char *ft_strndup(char *s, int n)
{
	int i;
	char *ptr;

	if (!(ptr = (char*)malloc(sizeof(char) * (n + 1))))
		return (0);
	i = 0;
	while (s[i] && i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

// 3. 서식자의 위치를 찾아주는 함수
char *find_idx(char *s)
{
	int i;
	i = 0;
	// 문자가 존재하고 숫자나 점인 경우 idx++
	while (s[i] && (('0' <= s[i] && s[i] <= '9') || s[i] =='.'))
		i++;
	// 출력 가능한 문자이고
	if (32 <= s[i] && s[i] <= 126)
	{
		// 서식문자라면
		if (s[i] == 's' || s[i] == 'd' || s[i] == 'x')
			return (s + i); // 서식 문자 위치 반한
		else
			return (0);
	}
	return (0);
}

// 2. %를 찾아서 처리해주는 함수
int check_format(va_list ap, char *s)
{
	int i;
	char *conversion; // %의 위치 반환
	int ret;
	char *format;

	ret = 0;
	i = 0;
	while (s[i])
	{
		// %를 만나게 되면
		if (s[i] == '%')
		{
			conversion = find_idx(s + i + 1); // 서식 문자 s, d, x를 찾는다
			// 서식 문자를 찾으면
			if (conversion)
			{
				format = ft_strndup(s + i, (conversion + 1) - (s + i)); // fomartting 할 내용을 담는다
				ret += print_with_flags(format, *conversion, ap); // 출력
				i += ((conversion) - (s + i)); // 인덱스 이동
			}
			else // s, d, x가 없을 때
				i++;
		}
		else // % 없을 때 문자 출력
		{
			write(1, &s[i], 1);
			ret++;
		}
		i++;
	}
	return (ret);
}

// 1. ft_printf 함수
int ft_printf(const char *s, ...)
{
	int ret;
	va_list ap;

	if (!s)
		return (-1);
	va_start(ap, s);
	ret = check_format(ap, (char *)s);
	va_end(ap);
	return (ret);
}
