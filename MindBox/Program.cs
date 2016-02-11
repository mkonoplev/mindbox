﻿using System;

namespace MindBox
{
    public class Program
    {
        /// <summary>
        /// Вычисляет площать прямоугольного треугольника, заданного длинами его сторон.
        /// </summary>
        /// <param name="a">Сторона A (катет).</param>
        /// <param name="b">Сторона Б (катет).</param>
        /// <param name="c">Сторона C (гипотенуза).</param>
        /// <returns>Площать прямоугольного треугольника.</returns>
        /// <exception cref="ArgumentException">Выбрасывается когда длины сторон треугольника не удовлетворяют т.Пифагора.</exception>
        /// <exception cref="ArgumentOutOfRangeException">Выбрасывается когда длинна одной из сторон меньше или равна нулю.</exception>
        /// <remarks>
        /// Для вычисления площади треугольника по 3сторонам используется формула Герона:
        /// S = 1/4 * Math.Sqrt((a + b + c)(b + c - a)(a + c - b)(a + b - c))
        /// Для проверки того, что треугольник являетя прямоугольным используется т.Пифагора:
        /// a * a + b * b - c * c
        /// 
        /// Функция не выполняет никаких проверкок правильности арифметики для чисел с плавающей точкой.
        /// Некоторые пояснения даны по коду.
        /// </remarks>
        public static float FindRightTriangleArea(float a, float b, float c)
        {
            if (a < 0) { throw new ArgumentOutOfRangeException("a", "Длина стораны 'a' должна быть больше или равна нулю."); }
            if (b < 0) { throw new ArgumentOutOfRangeException("b", "Длина стораны 'b' должна быть больше или равна нулю."); }
            if (c < 0) { throw new ArgumentOutOfRangeException("c", "Длина стораны 'c' должна быть больше или равна нулю."); }

            // При использовании функции необходимо учитывать:
            //     1. правила арифметики чисел с плавающей точкой и, конечно же, 
            //     2. точность вычислений (float выбран чтобы упростить пояснение).
            //
            // Например, при вызове FindRightTriangleArea(10000.0f, 1.0f, 10000.0f):
            // a*a + b*b = 100000000.0f, поскольку float имеет точность 7 цифр и 1 это уже 8ая цифра, которая будет отброшена,
            // что позволит пройти коду проверку по т.Пифагора...
            if (Math.Abs(c * c - (a * a + b * b)) > float.Epsilon)
            {
                throw new ArgumentException("Длины сторон треугольника не удовлетворяют условию т. Пифагора (т.е. a*a + b*b != c*c)");
            }
            // ...но, и тут есть нюанс! Арифметика с плавающей точкой выполняется, с точностью доступной на компьютере конечного пользователя
            // (из спецификации C#: '...floating-point operations may be performed with higher  precision than the result type of the operation..'),
            // и, к примеру, на моем компьютере все-таки будет выбрашенно исключение. Если переписать кода проверки следующим образом:
            //  float f1 = a * a + b * b;
            //  float f2 = c * c;
            //  if (Math.Abs(f2 - f1) > float.Epsilon)
            //  {
            //      throw new ArgumentException("Длины сторон треугольника не удовлетворяют условию т. Пифагора (т.е. a*a + b*b != c*c)");
            //  }
            // это заставляет компилятор вызывать инструкцию 'stloc.x' при выполнении которой и будет отброшен незначащий разряд.
            // Впрочем, дело это не меняет. Для double так же можно подобрать пример, приводящий к аналогичному результату.
            return (float)(1.0f / 4.0f * Math.Sqrt((a + b + c) * (b + c - a) * (a + c - b) * (a + b - c)));
        }
    }
}
