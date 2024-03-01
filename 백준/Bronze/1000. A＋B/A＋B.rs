use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("");
    let mut splitString: Vec<&str> = input.split(' ').collect();
    let mut a = &splitString[0];
    let mut b = &splitString[1];
    let a: u32 = a.trim().parse().expect("");
    let b: u32 = b.trim().parse().expect("");
    println!("{}", a + b);
}