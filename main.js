const readline = require('readline');

const perguntas = [
    "Você gosta de esportes?",
    "Você gosta de música?",
    "Você gosta de filmes?",
    "Você gosta de programar?",
    "Você gosta de viajar?"
];
const respostas = [];

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

console.log("Responda com 1 para Sim e 2 para Não.\n");

let index = 0;

function fazerPergunta() {
    if (index < perguntas.length) {
        rl.question(`${perguntas[index]}: `, (resposta) => {
            if (resposta === '1' || resposta === '2') {
                respostas.push(resposta === '1' ? 'Sim' : 'Não');
                index++;
                fazerPergunta();
            } else {
                console.log("Resposta inválida. Responda com 1 para Sim ou 2 para Não.");
                fazerPergunta();
            }
        });
    } else {
        console.log("\nSuas respostas foram:\n");
        perguntas.forEach((pergunta, i) => {
            console.log(`${pergunta} ${respostas[i]}`);
        });
        rl.close();
    }
}

fazerPergunta();
