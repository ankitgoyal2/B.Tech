function myfunction()
{
    alert("Hello User");
}
// ===================================================================================
//  let array=['ankit','vikas','vinod','vivek','pallavi']

//     console.log(arr.length)

//     console.log(arr[arr.length-1])
// ===================================================================================
//     console.log(`i am ${arr[arr.length-1]} here.`)
// ===================================================================================
// let fun =function(name='ankit ',first='12'){
//     console.log(name+first)
// }
// fun('vikas')
// ===================================================================================
// for (let index = 0; index < array.length; index++) {
//     const element = array[index];
// }
// ===================================================================================
// array.forEach(myfun);

// function myfun(a,b,c,d) {
//     console.log(a+b+c+d)
// }
// ===================================================================================
// console.log(typeof array)
// let myobj={ title:'myfile',
//             desc:'this ois the descprition',
//             myfunction:function(){
//                 this.desc='its changed'
//             }
// }
// myobj.myfunction();
// console.log(myobj);
// ===================================================================================
// let a=2
// let b='2'
// console.log(a===b);

// ===================================================================================
// let obj=[{name:"ankit",age:20},
//          {name:"shubham" ,age:30}]

// let findfunction=function (anyobj,title) {

//     let result=anyobj.find(function(item){
//         return item.name==title
//     })

//     return result;
// }
// let a=findfunction(obj,'shubham')
// console.log(a);

// ===================================================================================
// // ============type 1===================
// var a=function(name){
//     return "i am inside the function "+name
// }
// console.log(a('ankit'));

// //==========type 2=================
// var an=(name)=>{
//     return "i am inside the function "+name
// }
// console.log(an('ankit'));

// //========type 3=================
// var fun1=(name)=>"hey there ${name} its nice to see you"
// console.log(fun1(`vicky`));

// //========type 4=================
// var fun2=(name)=>(`hey there ${name} its nice to see you`)
// console.log(fun2(`vicky`));

// ===================================================================================
// let arr=[{title:'ankit',
//             age:19},
//         {title:'me',
//         age:26},
//     {title:'you',
//     age:45}]

// // let result=arr.filter((item)=>{
// //     return item.age>20
// // })

// //above function is same asbelow function
// let result=arr.filter( (item) => item.age>20 )
// console.log(result);
//=============================================================================================
// console.log('5'+5);
// console.log('5'-5);
// console.log(true+5);
// console.log(true-5);
// console.log(true+'5');
// console.log(true-'5');
//===================================================================================
// this is considered false
// false,0,null,undefined,''
//===================================================================================
// let obj1={name:'noereog',age:'20'}
// let obj2={name:'lsmf',age:'30'}

// let mymap=new Map();
// mymap.set('key1',obj1)
// mymap.set('key2',obj2)

// console.log(typeof mymap);
// console.log(mymap);
// console.log(mymap.get('key1'));

// console.log(mymap.keys());
// console.log(mymap.values());
// console.log(mymap.entries());

// for (const itr of mymap.keys()) {
//     console.log(itr);
// }
// for (const [mykey,myvalue] of mymap.entries()){
//     console.log(mykey+'==>'+myvalue.name);
// }

// mymap.forEach((abc,ghi)=>console.log(ghi+'---->'+abc.age))  


// let arr=[["a","b","z"],
//         ["c","d"],
//         ["e","f","y"]
// ]
// let freshmap=new Map(arr)
// console.log(freshmap);

//===================================================================================

