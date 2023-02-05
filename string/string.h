#pragma once
namespace hyt {
   class string {
        public:
            typedef char* iterator;

            string(const char* str = "") {
                _size = strlen(str);
                _capacity = _size;
                _str = new char[_capacity + 1];
                strcpy(_str, str);
            }
            string(const string& s) 
            {
                _str = new char[s._capacity + 1];
                _size = s._size;
                _capacity = s._capacity;
                strcpy(_str, s._str);
            }
            string& operator=(const string& s) {
                if(this != &s) {
                    char* tmp = new char[_capacity + 1];
                    strcpy(tmp, _str);
                    delete[] _str;
                    _str = tmp;
                    _size = s._size;
                    _capacity = s.capacity();
                }
                return *this;
            }
            ~string() {
                if(_str) {
                    _size = 0;
                    _capacity = 0;
                    delete[] _str;
                    _str = nullptr;
                }
            }

            iterator begin() {
                return _str;
            }
            iterator begin() const {
                return _str;
            }

            iterator end() {
                return _str + _size;
            }
            iterator end() const {
                return _str + _size;
            }

            void push_back(char c) {
                if(_size == _capacity) { 
                    size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
                    reserve(newCapacity );
                }
                _str[_size++] = c;
                _str[_size] = '\0';
            }
            string& operator+=(char c) {
                push_back(c);
                return *this;
            }
            void append(const char* str) {
                size_t len = strlen(str);
                if(_size + len > _capacity) {
                    reserve(_size + len);
                }
                strcpy(_str + len, str);
                _size += len;
            }
            string& operator+=(const char* str) {
                append(str);
                return *this;
            }
            void clear() {
                _size = 0;
                _str[_size] = '\0';
            }
            void swap(string& s) {
                str::swap(_str,s._str);
                str::swap(_size,s._size);
                str::swap(_capacity,s._capacity);
            }

            const char* c_str()const {
                return _str;
            }

            size_t size()const {
                return _size;
            }
            size_t capacity()const {
                return _capacity;
            }
            bool empty()const {
                return _size == 0;
            }
            void resize(size_t n, char c = '\0') {
                if(n <= _size) {
                    _size = n;
                    _str[_size] = '\0';
                }else {
                    reserve(n);
                    for(size_t i = _size; i < n; i++) {
                        _str[i] = c;
                    }
                    _size = n;
                    _str[_size] = '\0';
                }
            }

            void reserve(size_t n) {
                if(n > _capacity) {
                    char* tmp = new char[n + 1];
                    strcpy(tmp, _str);
                    delete[] _str;
                    _str = tmp;
                    _capacity = n;
                }
            }

            char& operator[](size_t index) {
                assert(index < _size);
                return _str[index];
            }
            const char& operator[](size_t index)const {
                assert(index < _size);
                return _str[index];
            }

            bool operator<(const string& s) {
                for(size_t i = 0; i < s._size; i++) {
                    if(s[i] > _str[i]) {
                        return true;
                    }else if(s[i] < _str[i]) {
                        return false;
                    }
                }
                return false;
                
            }
            bool operator<=(const string& s) {
                return *this < s || *this == s;
            }
            bool operator>(const string& s) {
                return !(*this <= s);
            }
            bool operator>=(const string& s) {
                return *this > s || *this == s;
            }
            bool operator==(const string& s) {
                if(_size != s._size) {
                    return false;
                }
                for(size_t i = 0; i < s._size; i++) {
                    if(s[i] != _str[i]) {
                        return false;
                    }
                }
                return true;
            }
            bool operator!=(const string& s) {
                return !(*this == s);
            }

             // 返回c在string中第一次出现的位置

            size_t find (char c, size_t pos = 0) const {
                asssert(pos < _size);
                for(size_t i = pos; i < _size; i++) {
                    if(_str[i] == c) {
                        return i;
                    }
                }
                return npos;
            }

            // 返回子串s在string中第一次出现的位置

            size_t find (const char* s, size_t pos = 0) const {
                assert(pos < _size); 
                const char* ptr = strstr(_str + pos, s);
                if(ptr == nullptr) {
                    return npos;
                }else {
                    return ptr - _str;
                }
            }

            // 在pos位置上插入字符c/字符串str

            string& insert(size_t pos, char c) {
                assert(pos <= _size);
                if(_size == _capacity) { 
                    size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
                    reserve(newCapacity );
                }
                for(int i = _size; i >= (int)pos; i--) {
                    _str[i + 1] = _str[i];
                }
                _str[pos] = c;
                size++;
                return *this;
            }

            string& insert(size_t pos, const char* str){
                assert(pos <= _size);
                size_t len = strlen(str);
                if(_size + len > _capacity) {
                    reserve(_size + len);
                }
                size_t end = _size + len;
                while(end > pos + len - 1) {
                    _str[end] = _str[end - len];
                    end--;
                }
                strncpy(_str + pos, str, len);
                return *this
            }

            // 删除pos位置上的元素
            string& erase(size_t pos, size_t len) {
                assert(pos < _size);
                if(pos + len >= _size) {
                    _str[pos] = '\0';
                    _size = pos;
                }else {
                    strcpy(_str + pos, _str + pos + len);
                }
                eturn *this;
            }

        private:

            char* _str;
            size_t _capacity;
            size_t _size;

            const static size_t npos = -1;
   }

   ostream& operator<<(ostream& out, const string& str) {
        for (size_t i = 0; i < str.size(); i++)
        {
            cout << s[i];
        }
        
        return out;
   }

   istream& operator>>(istream& in, string& str) {

        char buff[128] = {'\0'};
        char ch = in.get();
        size_t i = 0;
        while(ch != '\0' && ch != '\n') {
            if(i == 127) {
                str += buff;
                i = 0;
            }
            buff[i++] = ch;
            ch = in.get();
        }
        if(i > 0) {
            buff[i] = '\0';
            str += buff;
        }
        return in;
   }

}