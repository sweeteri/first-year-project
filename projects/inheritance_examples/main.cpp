#include <iostream>

int main() {
	{ // 01. Порядок вызова конструкторов и деструкторов
		std::cout << "01. Порядок вызова конструкторов и деструкторов" << std::endl;
		class A {
			public:
				A() { std::cout << "A" << std::endl; }
				~A() { std::cout << "~A" << std::endl; }
		};
		class B: public A {
			public:
				B() { std::cout << "B" << std::endl; }
				~B() { std::cout << "~B" << std::endl; }
		};
		//B x;
	}
	{ // 02. Спецификатор видимости
		std::cout << "02. Спецификатор видимости" << std::endl;
		class A {
			public:
				A() {}
				~A() {}
				void print() { std::cout << "A::print" << std::endl; }
		};
		class B: protected A {
			public:
				B() {}
				~B() {}
				using A::print;
		};
		//B x;
		//x.print();
	}
	{ // 03. delete
		std::cout << "03. delete" << std::endl;
		class A {
			public:
				A() { std::cout << "A" << std::endl; }
				A(const A&) = delete;
				A(A&&) { std::cout << "A&&" << std::endl; }
				~A() { std::cout << "~A" << std::endl; }
		};
		class B: public A {
			public:
				B() { std::cout << "B" << std::endl; }
				B(const B&) { std::cout << "const B&" << std::endl; }
				B(B&&) { std::cout << "B&&" << std::endl; }
				~B() { std::cout << "~B" << std::endl; }
		};
		//B xb;
		//A xa(xb);
	}
	{ // 04. Статическое связывание и КП
		std::cout << "04. Статическое связывание и КП" << std::endl;
		class A {
			public:
				A() { std::cout << "A" << std::endl; }
				A(const A&) { std::cout << "const A&" << std::endl; }
				A(A&&) { std::cout << "A&&" << std::endl; }
				~A() { std::cout << "~A" << std::endl; }
		};
		class B: public A {
			public:
				B() { std::cout << "B" << std::endl; }
				B(const B&) { std::cout << "const B&" << std::endl; }
				B(B&&) { std::cout << "B&&" << std::endl; }
				~B() { std::cout << "~B" << std::endl; }
		};
		//A x = B();
	}
	{ // 05. Динамическое связывание без virtual
		std::cout << "05. Динамическое связывание без virtual" << std::endl;
		class A {
			public:
				A() { std::cout << "A" << std::endl; }
				~A() { std::cout << "~A" << std::endl; }
		};
		class B: public A {
			public:
				B() { std::cout << "B" << std::endl; }
				~B() { std::cout << "~B" << std::endl; }
		};
		/*B* xb = new B();
		delete xb;
		A* xa = new B();
		delete xa;*/
	}
	{ // 06. Динамическое связывание и virtual деструктор
		std::cout << "06. Динамическое связывание и virtual деструктор" << std::endl;
		class A {
			public:
				A() { std::cout << "A" << std::endl; }
				virtual ~A() { std::cout << "~A" << std::endl; }
		};
		class B: public A {
			public:
				B() { std::cout << "B" << std::endl; }
				~B() { std::cout << "~B" << std::endl; }
		};
		//A* xa = new B();
		//delete xa;
	}
	{ // 07. Наследование и virtual
		std::cout << "07. Наследование и virtual" << std::endl;
		class A {
			public:
				A() {}
				virtual ~A() {}
				void print() { std::cout << "A::print" << std::endl; }
				virtual void vm() { std::cout << "A::vm" << std::endl; }
		};
		class B: public A {
			public:
				B() {}
				~B() {}
				void print() { std::cout << "B::print" << std::endl; }
				void vm() { std::cout << "B::vm" << std::endl; }
		};
		/*A* xa = new B();
		xa->print();
		xa->vm();*/
	}
	{ // 08. Абстрактный класс
		std::cout << "08. Абстрактный класс" << std::endl;
		class A {
			public:
				A() { std::cout << "A" << std::endl; }
				A(const A&) { std::cout << "const A&" << std::endl; }
				A(A&&) { std::cout << "A&&" << std::endl; }
				virtual ~A() { std::cout << "~A" << std::endl; }
				virtual void print() = 0;
		};
		class B: public A {
			public:
				B() { std::cout << "B" << std::endl; }
				~B() { std::cout << "~B" << std::endl; }
				void print() { std::cout << "B::print" << std::endl; };
		};
		//A a;
	}
	{ // 09. Вызов виртуальной Ф из КпоУ
		std::cout << "09. Вызов виртуальной Ф из КпоУ" << std::endl;
		class A {
			public:
				A() { std::cout << "A" << std::endl; }
				virtual void print() { std::cout << "A::print" << std::endl; }
		};
		class B: public A {
			public:
				B() { std::cout << "B" << std::endl; print(); }
		};
		class C: public B {
			public:
				C() { std::cout << "C" << std::endl; }
				void print() { std::cout << "C::print" << std::endl; };
		};
		//C x;
	}
	{ // 10. Множественное наследование print
		std::cout << "10. Множественное наследование print" << std::endl;
		class A {
			public:
				void print() { std::cout << "A::print" << std::endl; };
		};
		class B {
			public:
				void print() { std::cout << "B::print" << std::endl; };
		};
		class C: public A, public B {};
		//C x;
		//x.print();
	}
	{ // 11. Множественное наследование Ромб
		std::cout << "11. Множественное наследование Ромб" << std::endl;
		class A {
			int value[10];
		};
		class B: public A {};
		class C: public A {};
		class D: public B, public C {};
		//std::cout << sizeof(D) << std::endl;
	}
	{ // 12. Множественное наследование Ромб 2
		std::cout << "12. Множественное наследование Ромб 2" << std::endl;
		class A {
			public: 
				int value;
				A() : value(10) {};
		};
		class B: public A {};
		class C: public A {};
		class D: public B, public C {};
		/*D d;
		d.B::value = 1;
		std::cout << d.C::value << std::endl;*/
	}
	
	return 0;
}
