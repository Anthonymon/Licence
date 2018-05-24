class CString
{
	private:
		char *chaine;
		int size;
		static int nbreChaines;
	
	public:
		CString();
		CString(const char *chaine);
		CString(const char c);
		CString(const CString& s);
		~CString();
		static int getNbrChaine(){ return CString::nbreChaines; }
		const char* getString() const;
		char getChar(int i) const;
		int getSize() const;
		CString& operator=(const CString& s);
		bool operator>(CString mot);
		bool operator<=(CString mot);
		CString& operator+(char c);
		CString plusGrand(CString s);
		bool operator==(const CString& c);
};
