use std::io;

fn main()
{
    // vals
    let mut nums = String::new();
    io::stdin().read_line(&mut nums).expect("");
    let split_string : Vec<&str> = nums.split(' ').collect();
    
    let mut total : u32 = 0;
    for _num in split_string
    {
        let num : u32 = _num.trim().parse().expect("");
        total += num * num;
    }
    println!("{}", total % 10);
}