const gplist = document.querySelector('#gp-list');
const form = document.querySelector('#add-gp-form');
// create element and render gp
function rendergp(doc){
    let li = document.createElement("li");
    let postcode = document.createElement('span');
    let available = document.createElement('span');

    li.setAttribute('data-id', doc.id)
    postcode.textContent = doc.data().postcode;
    available.textContent = doc.data().available;

    li.appendChild(postcode);
    li.appendChild(available);

    gplist.appendChild(li);
}
//getting data
db.collection('vaccince').get().then(snapshot => {
    snapshot.docs.forEach(doc => {
        rendergp(doc);
    })
});
// saving data 
form.addEventListener('submit', (event) => {
    event.preventDefault();
    db.collection('vaccince').add({
        postcode: form.postcode.value,
        available: form.available.value
    });
    form.postcode.value = '';
    form.available.value = '';
});