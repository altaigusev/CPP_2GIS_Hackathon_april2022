# CPP_2GIS_Hackathon_april2022
Task and solution
# Coding Test: data search

Алгоритм реализован следующим образом:

0. Подготовка к поиску: Проверяем корректность данных, чтобы needle не был больше, чем haystack, а threshold не больше того и другого. после этого копируем участок длиной threshold из needle в вектор shortNeedle.


1. Берем первый байт в последовательности needle и ищем его вхождение в последовательность haystack
2. Если такой байт был найден, то проверяем последующие байты на соответствие друг другу. Для этого используется копирование участка массива haystack длиной threshold в вектор shortHaystack и делаем прямое сравнение перегруженным оператором `==` между ними. И здесь возникает ветвление:

	2.1. Если оба вектора оказались равны, то мы проверяем следующее условие - а можем ли мы увеличить threshold? Если да, то делаем новые копии участков, если нет, то тогда это и есть наш ответ - возвращаем нашей программе позицию первой буквы, длину совпавшего элемента и то, какой сдвиг внутри needle мы сделали. Сдвигаем итератор на 1 позицию вперед и начинаем сравнивать с оставшейся частью строки. Если ничего не найдено, то мы (если это возможно) сдвигаем наш needle на ещё один символ и ищем снова с начала строки.

	2.2. Если же векторы не равны, то мы \

3. 


## Описание классов и методов

Решение представлено классами:

> FileReader

Методы класса:

	class FileReader {
	private:
		std::string _filename;

	public:
	FileReader();
	FileReader(std::string filename);
	~FileReader();
	std::vector<int8_t> getVectorFromFile();
	};


> SequenceFinder

Методы класса:

	class SequenceFinder {
		public:
		SequenceFinder();
		~SequenceFinder();
		bool findTheSequence(const std::vector<int8_t> haystack, std::vector<int8_t> needle, uint32_t threshold); // Based on vector template method "find"
    bool findTheSequence2(const std::vector<int8_t> haystack, std::vector<int8_t> needle, uint32_t threshold); // Based on cutting elememts in front
		bool preparator(const std::vector<int8_t> haystack, std::vector<int8_t> needle);
		void zeroFiller(std::vector<int8_t>& vec, int32_t offset, int32_t threshold);
		void shortVectorReset(std::vector<int8_t>& vec, int32_t offset, int32_t threshold, std::vector<int8_t>& shortVector);
		void shortVectorReset(std::vector<int8_t>::iterator it1, std::vector<int8_t>::iterator it2, std::vector<int8_t>& shortVector);
	};
