


// <------------closuer----------->
// function a()
// {
//     let x=67;
//        function b()
//        {
//            console.log(x);
//        }
//        return b();
// }
// var xyz=a();
// console.log(xyz);


// // console.log(xyz);
// abc=35;
// console.log(isNaN(abc));

// abc=43;
// yz="43";
// console.log(abc==yz);
// console.log(abc===yz);



// block scope 
// for(let num=1;num<=10;){
//   console.log(num); //infinte loop
//   num++;
// }

// var myName = "thapa technical";
// console.log(myName);

// myName = "vinod thapa";
// console.log(myName);

// let myName = "thapa technical";
// console.log(myName);

// myName = "vinod thapa";
// console.log(myName);


// const myName = "thapa technical";
// console.log(myName);

// myName = "vinod thapa";
// console.log(myName);

// function abc()
// {
//     for(let i=0; i < 10; i++)
//     {
//         console.log(i);
//     }
// }
// abc();


function mult(a,b=3,c=4){
  return a*b*c;
}

console.log(mult(3,2));