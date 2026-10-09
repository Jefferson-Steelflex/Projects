const buttons = document.querySelector(".buttons"); /* pay attention to what type of selectors you must use
                                                       classes = .class, id's = "id" without a dot or # */
const display = document.querySelector(".display");

const increase = document.getElementById("increase");
const decrease = document.getElementById("decrease");
const reset = document.getElementById("reset");

let count = 0;
//trigger 
//update
//display

increase.addEventListener("click", () => {
    
    count = count + 1;

    display.textContent = count;
});
 
decrease.addEventListener("click", () => {
    
    count = count - 1;

    display.textContent = count;
});

reset.addEventListener("click", () =>  {
    count = 0;
    display.textContent = 0;
});