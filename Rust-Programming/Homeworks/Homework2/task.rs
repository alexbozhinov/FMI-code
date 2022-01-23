use std::ops::Mul;
use std::ops::Add;
#[derive(Debug)]

pub struct Matrix<T: Clone> {
    //first_row: Vec<Cell<T>>,
    //second_row: Vec<Cell<T>>,
    first_1: Cell<T>,
    first_2: Cell<T>,
    second_1: Cell<T>,
    second_2: Cell<T>,
}

#[derive(Debug, Clone, PartialEq)]
pub struct Cell<T>(pub T);

impl<T: Clone> Matrix<T> {
    /// Данните се очаква да бъдат подадени със статичен масив -- вижте по-долу за примери за
    /// конструиране. Какви може да са елементите? Ще тестваме само с два типа: String и i32.
    ///
    /// Очаква се да бъдат подадени по редове, от ляво надясно. Тоест, ако подадем като вход списък
    /// с елементи: 1, 2, 3, 4, се очаква конструираната матрица:
    ///
    /// | 1 2 |
    /// | 3 4 |
    ///
    /// Забележете, че подаваме като вход някакъв slice -- reference тип. Не очакваме матрицата да
    /// държи reference, клонирайте си данните, за да имате ownership.
    ///
    pub fn new(data: &[T; 4]) -> Matrix<T> {
        let cell0 = Cell(data[0].clone());
        let cell1 = Cell(data[1].clone());
        let cell2 = Cell(data[2].clone());
        let cell3 = Cell(data[3].clone());
        /*let mut row1 = Vec::<Cell<T>>::new();
        row1.push(cell0);row1.push(cell1);
        let mut row2 = Vec::<Cell<T>>::new();
        row2.push(cell2);row2.push(cell3);
        
       Matrix{first_row : row1,second_row : row2}*/
       Matrix{first_1: cell0, first_2: cell1, second_1: cell2, second_2: cell3}
    }

    /// Връща вектор, който съдържа в себе си всички 4 елемента на матрицата, наредени по редове,
    /// от ляво надясно и от горе надолу, обвити в `Cell`. Тоест, ако матрицата изглежда така:
    ///
    /// | 1 2 |
    /// | 3 4 |
    ///
    /// Очакваме `.by_row` да върне елементите в ред: 1, 2, 3, 4
    ///
    pub fn by_row(&self) -> Vec<Cell<T>> {
        let mut row = Vec::<Cell<T>>::new();
        row.push(self.first_1.clone());
        row.push(self.first_2.clone());
        row.push(self.second_1.clone());
        row.push(self.second_2.clone());
        
        return row
    }

    /// Връща вектор, който съдържа в себе си всички 4 елемента на матрицата, наредени по колони,
    /// от горе надолу и от ляво надясно, Обвити в `Cell`. Тоест, ако матрицата изглежда така:
    ///
    /// | 1 2 |
    /// | 3 4 |
    ///
    /// Очакваме `.by_col` да върне елементите в ред: 1, 3, 2, 4
    ///
    pub fn by_col(&self) -> Vec<Cell<T>> {
        let mut row = Vec::<Cell<T>>::new();
        row.push(self.first_1.clone());
        row.push(self.second_1.clone());
        row.push(self.first_2.clone());
        row.push(self.second_2.clone());
        
        return row
    }

}



impl Add<Cell<String>> for Cell<i32> {
    type Output = Cell<String>;
 
     fn add(self, other: Cell<String>) -> Cell<String> {
         let mut new_cell = Cell{0:String::from("")};
         if self.clone().0>=0{
         new_cell.0 = format!("{}{}{}", self.clone().0.to_string()," ",other.clone().0.to_string());
         }else{
            let mut _t = other.clone().0.chars().rev().collect::<String>();
            let mut _n = self.clone().0*(-1);
            new_cell.0=format!("{}{}{}", _t.to_string()," ",_n.to_string())
         }
        return new_cell;
        }
    }


    impl Mul<Cell<String>> for Cell<i32> {
        type Output = Cell<String>;
     
        fn mul(self, other: Cell<String>) -> Cell<String> { 
            let mut new_cell = Cell{0:String::from("")};
            if self.clone().0>=0{
                let mut _t = format!("{}","");
                for _i in 0..self.clone().0{
                    _t = format!("{}{}",_t,other.clone().0);
                }
                new_cell.0 = format!("{}",_t);
            }else{
                let mut _t = format!("{}","");
                let reversed = other.clone().0.chars().rev().collect::<String>();
                for _i in 0..self.clone().0*(-1){
                    _t = format!("{}{}",_t,reversed.clone());
                }
                new_cell.0 = format!("{}",_t);
            }
            return new_cell;
        }
    }



    impl Add<Matrix<String>> for Matrix<i32> {
        type Output = Matrix<String>;
     
         fn add(self, other: Matrix<String>) -> Matrix<String> {
            let mut new_matrix = Matrix::new(&[
                String::from(""), String::from(""),
                String::from(""), String::from("")
            ]);
            new_matrix.first_1 = self.first_1 + other.first_1;
            new_matrix.first_2 = self.first_2 + other.first_2;
            new_matrix.second_1 = self.second_1 + other.second_1;
            new_matrix.second_2 = self.second_2 + other.second_2;


            return new_matrix;
            }
        }




     impl Mul<Matrix<String>> for Matrix<i32> {
        type Output = String;
     
        fn mul(self, other: Matrix<String>) -> String { 
            let mut new_string = format!("{}","");
            new_string = format!("{}{}",new_string.clone(),(self.first_1.clone() * other.first_1.clone()).0);
            new_string = format!("{}{}{}",new_string.clone()," ",(self.first_2.clone() * other.second_1.clone()).0);
            new_string = format!("{}{}{}",new_string.clone()," ",(self.second_1.clone() * other.first_2.clone()).0);
            new_string = format!("{}{}{}",new_string.clone()," ",(self.second_2.clone() * other.second_2.clone()).0);


            return new_string;
        }
    }       

          
 /*
fn main(){
    let data: [i32; 4] = [1,2,3,4];
    let matrix = Matrix::new(&data);
    println!("{:?}", matrix.first_1);
    println!("{:?}", matrix.by_row());
    println!("{:?}", matrix.by_col());
    let matrix1 = Matrix::new(&[1, 2, 3, 1]);
    let matrix2 = Matrix::new(&[
        String::from("one"), String::from("two"),
        String::from("three"), String::from("you get it")
    ]);
    
    //println!("{:?}", matrix1.by_row()[0]);
    //println!("{:?}", matrix1.by_col()[0]);
    let cell1 = Cell(3);
    let cell2 = Cell(String::from("twenty"));
    println!("{:?}",cell1.clone() + cell2.clone());
    println!("{:?}",cell1 * cell2);
    //println!("{:?}",(matrix1 + matrix2).by_row()[0]);
    println!("{}",matrix1 * matrix2);
 }

*/
