#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897

typedef struct		s_vec
{
	double x;
	double y;
}					t_vec;

double get_radian(int num)
{
	return num * (PI / 180);
}

// create vector
t_vec	vec_new(double x, double y)
{
	t_vec result;

	result.x = x;
	result.y = y;
	return (result);
}

// add vectors
t_vec	vec_add(t_vec a, t_vec b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

// sub vetors
t_vec	vec_sub(t_vec a, t_vec b)
{
	a.x -= b.x;
	a.y -= b.y;
	return (a);
}

// scalar multiplication
t_vec	vec_mul(t_vec a, double b)
{
	a.x *= b;
	a.y *= b;
	return (a);
}

// equation solver using determinant
t_vec	equation_solver(t_vec *coeff0, t_vec *coeff1, t_vec *constant)
{
	t_vec	result;
	double	det; // determinant

	det = coeff0->x * coeff1->y - coeff1->x * coeff0->y;
	result.x = (coeff1->y * constant->x - coeff1->x * constant->y) / det;
	result.y = (coeff0->x * constant->y - coeff0->y * constant->x) / det;
	return (result);
}

// vector rotation
t_vec	vec_rot_ccw(t_vec a, double angle)
{
	double	sin_angle;
	double	cos_angle;
	t_vec	result;

	sin_angle = sin(angle);
	cos_angle = cos(angle);
	result.x = cos_angle * a.x - sin_angle * a.y;
	result.y = sin_angle * a.x + cos_angle * a.y;
	return (result);
}

int main(void)
{
	t_vec vec1 = vec_new(2.0, 4.0);
	t_vec vec2 = vec_new(9.0, 7.0);
	t_vec u = vec_new(1.0, 2.0);
	t_vec v = vec_new(3.0, 1.0);
	t_vec a = {9.0, 8.0};

	// print vector 1
	printf("[%lf %lf]\n", vec1.x, vec1.y);

	// add vectors
	t_vec vec3 = vec_add(vec1, vec2);
	printf("[%lf %lf]\n", vec3.x, vec3.y);

	// sub vectors
	t_vec vec4 = vec_sub(vec2, vec1);
	printf("[%lf %lf]\n", vec4.x, vec4.y);

	// solve equation
	t_vec ans = equation_solver(&u, &v, &a);
	printf("[%lf %lf]\n", ans.x, ans.y);

	// vector rotation
	t_vec x = {1.0, 0.0};
	ans = vec_rot_ccw(x, get_radian(180));
	printf("[%lf %lf]\n", ans.x, ans.y);

	return (0);
}

