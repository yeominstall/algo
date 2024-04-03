use std::io;

fn main()
{
	let mut input1 = String::new();
	let mut input2 = String::new();
	io::stdin().read_line(&mut input1).expect("");
	io::stdin().read_line(&mut input2).expect("");
    let a: &str = &input1;
    let b: usize = input2.trim().parse().expect("");
    println!("{}", &a.chars().nth(b-1).unwrap());
}