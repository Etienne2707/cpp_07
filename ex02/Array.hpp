#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

template<typename T>
class Array
{
private:
    T *_array;
    unsigned int _size;
public:
    Array(){
        std::cout << yellow << "Default constructor call" << std::endl;
        this->_array = NULL;
        this->_size = 0;
    }
    Array(unsigned int n): _array(new T[n]), _size(n){
        std::cout << yellow << "Parametric constructor call" << std::endl;
    }
    
	Array(const Array &src): _size(src.size())
	{
		std::cout << "Copy Constuctor called" << std::endl;
        this->_array = NULL;
		*this = src;
	}
    ~Array(){
        if (this->_array != NULL)
            delete[] this->_array;
        std::cout << red << "Destructor constructor call" << std::endl;
    }
    T &operator[](unsigned int index) { 
   
			if (index >= this->_size || this->_array == NULL)
			{
                std::cout << "index: " << index << std::endl;
                throw Array<T>::WrongArrayAcces();
            }
            return (this->_array[index]);
          
    }
    Array &operator=(const Array &src)
		{
			if (this->_array != NULL)
				delete [] this->_array;
			if (src.size() != 0)
			{
				this->_size = src.size();
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->size(); i++)
					this->_array[i] = src._array[i];
			}
			return (*this);
		}
    class WrongArrayAcces : public  std::exception
    {
        public :    
            virtual const char	*what() const throw();
    };

    //Getter

    unsigned int size() const {return (this->_size);}
    // faire une execption qui sera dans l'overload de l'operator []
    //la fonction size return _size
    //          
};

template<typename T>
const char	*Array<T>::WrongArrayAcces::what() const throw()
{
    return ("You try to acces to an unisialized memory space !");
}

#endif