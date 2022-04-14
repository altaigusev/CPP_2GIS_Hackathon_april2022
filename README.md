# CPP_2GIS_Hackathon_april2022
Task and solution
# Coding Test: data search

В проекте реализованы 2 алгоритма поиска подстрок в соответствии с условиями задачи.


Первый алгоритм реализован следующим образом:

Перед переходом к непосредственно алгоритму стоит проверка на то, явялется ли массив (вектор) needle чтобы мы могли его применять в сооттветствии с заданием?


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
