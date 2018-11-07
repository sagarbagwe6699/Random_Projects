import React, { Component } from 'react';
import Counter from'./counter';
class Counters extends Component {
    state = {
        c:[
            {id:1,value:4},
            {id:2,value:0},
            {id:3,value:0},
            {id:4,value:0}
        ]
    }
    render() { 
        return ( <div>
            {this.state.c.map(count => <Counter key={count.id} value={count.value} />)}
        </div> );
    }
}
 
export default Counters;