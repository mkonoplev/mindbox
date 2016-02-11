using System;
using MindBox;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace TestProject
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Assert.AreEqual(6.0f, Program.FindRightTriangleArea(3, 4, 5));
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentOutOfRangeException))]
        public void TestMethod21()
        {
            Program.FindRightTriangleArea(-1, 0, 0);
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentOutOfRangeException))]
        public void TestMethod22()
        {
            Program.FindRightTriangleArea(0, -1, 0);
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentOutOfRangeException))]
        public void TestMethod23()
        {
            Program.FindRightTriangleArea(0, 0, -1);
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void TestMethod3()
        {
            Program.FindRightTriangleArea(3, 4, 6);
        }
    }
}
