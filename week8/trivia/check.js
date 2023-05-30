//check.js file for quiz

// Function for correct click for multipul choice question. If correct button clicked button turns green
// and feedback shows correct.
document.addEventListener('DOMContentLoaded', function(){
    let correct = document.querySelector('.correct');
    correct.addEventListener('click', function(){
        correct.style.backgroundColor = 'green';
        document.querySelector('#feedback1').innerHTML = 'Correct!';
    })
// Function for incorrect multipul choice selection button turns red and gives feedback of incorrect.
    let incorrect = document.querySelectorAll('.incorrect');
    for (let i = 0; i < incorrect.length; i++){
        incorrect[i].addEventListener('click', function(){
            incorrect[i].style.backgroundColor = 'red';
            document.querySelector('#feedback1').innerHTML = 'Incorrect';
        });
    }
// Function to check submission of Free Response Question gives feedback of Correct and turns gree.
// Else feedback given of incorrect and turns red.
    document.querySelector('#check').addEventListener('click', function(){
        let input = document.querySelector('input');
        if (input.value == 'Arkansas'){
            input.style.backgroundColor = 'green';
            document.querySelector('#feedback2').innerHTML = 'Correct!';
        }

        else {
            input.style.backgroundColor = 'red';
            document.querySelector('#feeback2').innerHTML = 'Incorrect';
        }
    })

})