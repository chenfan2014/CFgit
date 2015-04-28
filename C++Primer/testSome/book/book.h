#ifndef __BOOK_ITEM
#define __BOOK_ITEM 

#include <iostream>
#include <string>
#include <vector>

class itemBase{
    public:
        itemBase(const std::string &book = " ", double salePrice = 0.0)
            :isbn_(book), price_(salePrice)
        {}

        std::string book() const {
            return isbn_;
        }

        virtual double netPrice(std::size_t n) const{       //virtual是启动动态绑定
            return n * price_;
        }
        
        virtual void print(ostream &os, const itemBase &ib) const{
            os << "ISBN : " << ib.isbn_ << " Price : " << ib.price_;
        }

    private:
        std::string isbn_;
    protected:
        double price_;
};


class bulkItem : public itemBase{
    public:
        bulkItem(std::size_t minQty = 0, double discount = 0.0)
            :itemBase(), minQty_(minQty), discount_(discount)
        {}


        void print (ostream &os, const bulkItem & bi) const{
            itemBase::print(os, bi);
            os << " MinQty : " << bi.minQty_ << " Discount : " << bi.discount_ ;
        }
        double netPrice(std::size_t ) const;        //声明
    private:
        std::size_t minQty_;
        double discount_;
};

#endif  /*__BOOK_ITEM*/
