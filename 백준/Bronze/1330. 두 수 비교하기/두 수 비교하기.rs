use std::io;

fn main()
{
	let mut input = String::new();
	io::stdin().read_line(&mut input).expect("");
	let mut _split_string: Vec<&str> = input.split(' ').collect();
    let a = &_split_string[0];
    let b = &_split_string[1];
    let a: i32 = a.trim().parse().expect("");
    let b: i32 = b.trim().parse().expect("");
    if a < b
    {
        println!("<");
    }
    else if a == b
    {
        println!("==");
    }
    else
    {
        println!(">");
    }
}