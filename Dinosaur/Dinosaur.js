// Event Listeners and Handlers 
// Listens for specific events to create interactive behavior
// 1. Click Event: Changes box color and text on click
// 2. Mouseover Event: Changes box color and text on hover
// 3. Mouseout Event: Reverts box color and text when mouse leaves
// .addEventListener(event, callback(function)) 
//
//
//
// 1.) we use querySelector to select the grid and info panel elements from the DOM, 
//     in other words, we are telling the code which parts of the HTML we want to interact with/Use.
const grid = document.querySelector(".Dino-Grid");
const infoPanel = document.querySelector(".Dino-Card-Info");
//
//
// 2.) we use querySelectors again to select specific elements 
// within the info panel that will display dinosaur information.
//     El = Element
const nameEl = infoPanel.querySelector(".Dino-Name");
const eraEl = infoPanel.querySelector(".era");
const familyEl = infoPanel.querySelector(".family");
const genusEl = infoPanel.querySelector(".genus");
const heightEl = infoPanel.querySelector(".height");
const weightEl = infoPanel.querySelector(".weight");
const lengthEl = infoPanel.querySelector(".length");
const dietEl = infoPanel.querySelector(".diet");

const descriptionEl = infoPanel.querySelector(".description");
const discoveryEl = infoPanel.querySelector(".discovery");
const paleoecologyEl = infoPanel.querySelector(".paleoecology");

const imageEl = infoPanel.querySelector(".Dino-Image-Large");

// To save state

let savedScrollPosition = 0;

// Audio Setup
const ClickSound = new Audio("audio/A-ClickSound.wav");

// Back Button Event Listener
document.getElementById("Back-Button").addEventListener("click", () => {
    
    // Toggle Visibility (On-Off)
    infoPanel.classList.add("hidden");
    grid.classList.remove("hidden");
    window.scrollTo(0, savedScrollPosition);
});

// Now we add EventListeners whos main function is to listen 
// for a specific event in this case a click on any of the dinosaur cards.
// and run a function when that event occurs.
document.querySelectorAll(".Dino-Card").forEach(card => {
    card.addEventListener("click", () => {
        const data = card.querySelector(".Dino-Data").dataset;

        savedScrollPosition = window.scrollY;

        // Audio for click
        ClickSound.currentTime = 0;
        ClickSound.play();

        //Audio for Dinosaur Sound
        const dinoSoundsrc = data.sound;

        setTimeout(() => {
            const DinoSound = new Audio(dinoSoundsrc);
            DinoSound.play();
        }, 500); // Delay to sync with click sound

        // Toggle Visibility (On-Off)
        // Toggle Visibility (On-Off)
        grid.classList.add("hidden");
        infoPanel.classList.remove("hidden");

        // Fill Panel with Data
        nameEl.textContent = card.dataset.name;
        eraEl.textContent = data.era;
        familyEl.textContent = data.family;
        genusEl.textContent = data.genus;
        heightEl.textContent = data.height;
        weightEl.textContent = data.weight;
        lengthEl.textContent = data.length;
        dietEl.textContent = data.diet;

        descriptionEl.textContent = data.description;
        discoveryEl.textContent = data.discovery;
        paleoecologyEl.textContent = data.paleoecology;

        imageEl.src = data.image;
        imageEl.alt = card.dataset.name;

        
    });        
});
