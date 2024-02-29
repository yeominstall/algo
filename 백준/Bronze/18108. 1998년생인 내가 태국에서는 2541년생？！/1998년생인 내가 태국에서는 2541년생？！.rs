use std::io;

fn main()
{
    let mut y = String::new();
    
    io::stdin().read_line(&mut y).expect("");
    
    let num: i32 = y.trim().parse().expect("");
    println!("{}", num - 543);
}